//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

//This is where the game actually takes place!

#include "Player.h"
#include "ExploitCard.h"
#include "DefenseCard.h"
#include "cardTest.h"

using namespace std;

int main() {
    GameCard* ssrf = new ExploitCard("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
    GameCard* siem = new DefenseCard("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);


    //! temporary
    GameCard* ssrf2 = new ExploitCard("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
    GameCard* siem2 = new DefenseCard("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);

    //create player 1's deck
    //!TODO come up with a way to build decks that are pointers to COPIES of a random card (make sure to maintain the correct data type)

    //!TODO make this guarantee one exploitCard and one defenseCard (make 3 pools, one with all cards, one with exploits only, and one with defense only)
    vector<GameCard*> player1Deck;
    player1Deck.push_back(ssrf);
    player1Deck.push_back(siem);
    // player1Deck.push_back(*cardPool[rand() % 2]);

    //create player 2's deck
    vector<GameCard*> player2Deck;
    player2Deck.push_back(siem2);
    player2Deck.push_back(ssrf2);
    // player2Deck.push_back(*cardPool[rand() % 2]);

    Player p1(player1Deck);
    Player p2(player2Deck);

    cout << "Welcome to the unnamed Infosec Card game!!! :3" << endl;
    cout << "The game will now begin! and also like end when someone dies :)" << endl << endl;

    //main game loop
    while (p1.getPlayerHP() > 0 && p2.getPlayerHP() > 0) {
        cout << "Player 1 draws a card.";
        p1.drawCard();
        cout << " Their deck is now: " << endl;
        p1.printDeck();
        cout << endl;
        cout << "Player 1, enter the index of the card you want to play! (starting at 0): ";
        int indexToPlay;
        cin >> indexToPlay;
        cout << "Player 1 plays " << (p1.getPlayerCardList().at(indexToPlay)) ->getCardName();
        p1.playCard(indexToPlay, p2);
        if (p2.getPlayerHP() > 0) {
            cout << "Player 2 draws a card.";
            p2.drawCard();
            cout << " Their deck is now: " << endl;
            p2.printDeck();
            cout << endl;
            cout << "Player 2, enter the index of the card you want to play! (starting at 0): ";
            int indexToPlay;
            cin >> indexToPlay;
            cout << "Player 2 plays " << (p2.getPlayerCardList().at(indexToPlay)) ->getCardName();
            p2.playCard(indexToPlay, p1);
        }
    }
    

    return EXIT_SUCCESS;
}