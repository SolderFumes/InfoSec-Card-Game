//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#include "Player.h"

using namespace std;


//constructors
Player::Player() {
    playerHP = DEFAULT_PLAYER_HP;
    playerBandwidth = DEFAULT_PLAYER_BANDWIDTH;
    //both lists are empty
    //! TEMPORARY
    GameCard* ssrf = new ExploitCard("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
GameCard* siem = new DefenseCard("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);
cardPool[0] = ssrf;
cardPool[1] = siem;
}

Player::Player(int newHP, int newBandwidth, vector<GameCard*> newCardList) {
    //we actually DONT want to pass by reference here because we want each player to have their
    //own unique copy of cardList and not accidentally modify
    //a passed by reference variable, even though it saves time.
    playerHP = newHP;
    playerBandwidth = newBandwidth;
    cardList = newCardList;
    //cardsActive will get modified when cards are played/destroyed.

    //! TEMPORARY
    GameCard* ssrf = new ExploitCard("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
GameCard* siem = new DefenseCard("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);
cardPool[0] = ssrf;
cardPool[1] = siem;
}

Player::Player(vector<GameCard*> newCardList) {
    playerHP = DEFAULT_PLAYER_HP;
    playerBandwidth = DEFAULT_PLAYER_BANDWIDTH;
    cardList = newCardList;

    //! TEMPORARY
    GameCard* ssrf = new ExploitCard("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
GameCard* siem = new DefenseCard("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);
cardPool[0] = ssrf;
cardPool[1] = siem;
}

//GETTERS
int Player::getPlayerHP() const { return playerHP; }

int Player::getPlayerBandwidth() const { return playerBandwidth; }

vector<GameCard*>& Player::getPlayerCardList() { return cardList; }

vector<GameCard*>& Player::getPlayerCardsActive() { return cardsActive; }

void Player::printDeck() const {
    for (int i = 0; i < cardList.size(); i++) {
        cout << cardList.at(i)->toString() << endl;
    }
}

//SETTERS :3

void Player::setPlayerHP(int newHP) { playerHP = newHP; }

void Player::setPlayerBandwidth(int newBandwidth) { playerBandwidth = newBandwidth; } 

void Player::reducePlayerHP(int reduceBy) { playerHP -= reduceBy; }

void Player::reducePlayerBandwidth(int reduceBy) { playerBandwidth -= reduceBy; }

void Player::drawCard() {
    //add a random card from the cardPoo
    this->addCard(*cardPool[rand() % 2]);
}

void Player::addCard(GameCard cardToAdd) {
    //push a reference to a COPY of the card (everything is pointers for dynamic binding)
    cardList.push_back( new GameCard(cardToAdd) );
}

void Player::playCard(int index, Player& target) {
    //data validation
    if (index >= 0 && index < cardList.size()) {
        GameCard* playedCard = cardList.at(index);
        if (playerBandwidth >= playedCard->getBandwidthCost()) {
            playerBandwidth -= playedCard->getBandwidthCost();
        }
        else {
            cout << "Not enough Bandwidth!" << endl;
            return;
        }
        //if the card is a DefenseCard
        if (dynamic_cast<DefenseCard*>(playedCard) != nullptr) {
            //add the card (in cardList) to the end of our activeCards
            cardsActive.push_back(playedCard);
        }
        else {
            (dynamic_cast<ExploitCard*>(playedCard)->attack(target));
        }
        //now remove the card we just played from our deck
        cardList.erase(cardList.begin() + index);
    }
    else {
        cout << "invalid card index" << endl;
    }
}


//OTHER METHODS
void Player::display() {
    cout << "Player has " << playerHP << " HP and " << playerBandwidth << " bandwidth." << endl;
    cout << "Deck contains: ";
    for (int i = 0; i < cardList.size(); i++) {
        cout << cardList.at(i)->toString() << ", ";
    }
    cout << endl;
}

string Player::toString() {
    string returnString = "";
    returnString += "HP: " + playerHP;
    returnString += " | Bandwidth: " + playerBandwidth;
    returnString += " | Cards: ";
    for (int i = 0; i < cardList.size(); i++) {
        returnString += " | " + cardList.at(i)->toString();
    }

    return returnString;
}

bool Player::hasDefense() {
    //loop through every card. If we find a defenseCard, return true. otherwise, return false.
    for (int i = 0; i < cardsActive.size(); i++) {
        //this line tries to cast the GameCard as a DefenseCard, if it fails, it returns a nullptr.
        if (dynamic_cast<DefenseCard*>(cardsActive.at(i)) != nullptr) {
            return true;
        }
    }
    return false;
}

DefenseCard* Player::firstDefenseCard() {
    for (int i = 0; i < cardsActive.size(); i++) {
        if (dynamic_cast<DefenseCard*>(cardsActive.at(i)) != nullptr) {
            return (DefenseCard*) (cardsActive.at(i));
        }
    }
    return nullptr;
}