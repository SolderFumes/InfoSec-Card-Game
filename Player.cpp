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
}

Player::Player(int newHP, int newBandwidth, vector<GameCard*> newCardList) {
    //we actually DONT want to pass by reference here because we want each player to have their
    //own unique copy of cardList and not accidentally modify
    //a passed by reference variable, even though it saves time.
    playerHP = newHP;
    playerBandwidth = newBandwidth;
    cardList = newCardList;
    //cardsActive will get modified when cards are played/destroyed.
}

Player::Player(vector<GameCard*> newCardList) {
    playerHP = DEFAULT_PLAYER_HP;
    playerBandwidth = DEFAULT_PLAYER_BANDWIDTH;
    cardList = newCardList;
}

//GETTERS
int Player::getPlayerHP() const { return playerHP; }

int Player::getPlayerBandwidth() const { return playerBandwidth; }

vector<GameCard*>& Player::getPlayerCardList() { return cardList; }

vector<GameCard*>& Player::getPlayerCardsActive() { return cardsActive; }

//SETTERS :3

void Player::setPlayerHP(int newHP) { playerHP = newHP; }

void Player::setPlayerBandwidth(int newBandwidth) { playerBandwidth = newBandwidth; } 

void Player::reducePlayerHP(int reduceBy) { playerHP -= reduceBy; }

void Player::reducePlayerBandwidth(int reduceBy) { playerBandwidth -= reduceBy; }

void Player::addCard(GameCard cardToAdd) {
    //push a reference to a COPY of the card (everything is pointers for dynamic binding)
    cardList.push_back( new GameCard(cardToAdd) );
}

void Player::playCard(int index) {
    //data validation
    if (index >= 0 && index < cardList.size()) {
        //add the card (in cardList) to the end of our activeCards
        cardsActive.push_back(cardList.at(index));
        //now remove the card we just played from our deck
        cardList.erase(cardList.begin() + index);
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