//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "ExploitCard.h"
#include "DefenseCard.h"
#include "Player.h"

using namespace std;

void cardTest() {
    cout << boolalpha;
    cout << fixed << setprecision(2);
    
    GameCard defaultCard;
    string completeCardImageLink = "https://bleepstatic.com/content/posts/2017/06/07/ETERNALBLUE.jpg";
    GameCard completeCard("EternalBlue", "A famous exploit affecting almost all Windows Machines", 20, completeCardImageLink, Network);
    string cardPtrImageLink = "https://myrasecurity.com/assets/79302/1673879028-bedrohungen_code_injection_de_en_transparent_desktop.png";
    GameCard *cardPtr = new GameCard("SQL Injection", "The 3rd most dangerous Web Security Exploit", 10, cardPtrImageLink, Web);

    cout << "*** TESTING ACCESSOR METHODS :3 ***" << endl;
    //*** getCardName
    if (defaultCard.getCardName() == "NoName") {
        cout << "getCardName Test 1 Passed!" << endl;
    }
    else {
        cout << "getCardName Test 1 Failed!" << endl;
    }

    if (completeCard.getCardName() == "EternalBlue") {
        cout << "getCardName Test 2 Passed!" << endl;
    }
    else {
        cout << "getCardName Test 2 Failed!" << endl;
    }

    if (cardPtr->getCardName() == "SQL Injection") {
        cout << "getCardName Test 3 Passed!" << endl;
    }
    else {
        cout << "getCardName Test 3 Failed!" << endl;
    }
    
    //*** getCardDescription
    if (defaultCard.getCardDescription() == "NoDescription") {
        cout << "getCardDescription Test 1 Passed!" << endl;
    }
    else {
        cout << "getCardDescription Test 1 Failed!" << endl;
    }

    if (completeCard.getCardDescription() == "A famous exploit affecting almost all Windows Machines") {
        cout << "getCardDescription Test 2 Passed!" << endl;
    }
    else {
        cout << "getCardDescription Test 2 Failed!" << endl;
    }

    if (cardPtr->getCardDescription() == "The 3rd most dangerous Web Security Exploit") {
        cout << "getCardDescription Test 3 Passed!" << endl;
    }
    else {
        cout << "getCardDescription Test 3 Failed!" << endl;
    }
    
    //*** getBandwidthCost
    if (defaultCard.getBandwidthCost() == 1) {
        cout << "getBandwidthCost Test 1 Passed!" << endl;
    }
    else {
        cout << "getBandwidthCost Test 1 Failed!" << endl;
    }

    if (completeCard.getBandwidthCost() == 20) {
        cout << "getBandwidthCost Test 2 Passed!" << endl;
    }
    else {
        cout << "getBandwidthCost Test 2 Failed!" << endl;
    }

    if (cardPtr->getBandwidthCost() == 10) {
        cout << "getBandwidthCost Test 3 Passed!" << endl;
    }
    else {
        cout << "getBandwidthCost Test 3 Failed!" << endl;
    }
    
    //*** getImageLink
    if (defaultCard.getImageLink() == "https://c.stocksy.com/a/RQY500/z9/1323975.jpg") {
        cout << "getImageLink Test 1 Passed!" << endl;
    }
    else {
        cout << "getImageLink Test 1 Failed!" << endl;
    }

    if (completeCard.getImageLink() == completeCardImageLink) {
        cout << "getImageLink Test 2 Passed!" << endl;
    }
    else {
        cout << "getImageLink Test 2 Failed!" << endl;
    }

    if (cardPtr->getImageLink() == cardPtrImageLink) {
        cout << "getImageLink Test 3 Passed!" << endl;
    }
    else {
        cout << "getImageLink Test 3 Failed!" << endl;
    }

    cout << "*** TESTING MUTATOR METHODS :3***" << endl;
    defaultCard.setCardName("Firewall");
    defaultCard.setCardDescription("A basic security measure to stop unnecessary connections.");
    defaultCard.setBandwidthCost(5);
    defaultCard.setImageLink("https://compuquip.com/hs-fs/hubfs/images/blog-images/types-of-firewalls.jpg");

    cout << "Checking setCardName... " << (defaultCard.getCardName() == "Firewall") << endl;
    cout << "Checking setCardDescription... " << (defaultCard.getCardDescription() == "A basic security measure to stop unnecessary connections.") << endl;
    cout << "Checking setBandwidthCost... " << (defaultCard.getBandwidthCost() == 5) << endl;
    cout << "Checking setImageLink... " << (defaultCard.getImageLink() == "https://compuquip.com/hs-fs/hubfs/images/blog-images/types-of-firewalls.jpg") << endl;

    cout << endl;

    cout << "*** TESTING DISPLAY METHOD :3***" << endl;
    cout << "Should display:" << endl;
    cout << defaultCard.getCardName() << ": " << defaultCard.getCardDescription() << " Costs " << defaultCard.getBandwidthCost() << " Bandwidth."
         << " Image is stored at " << defaultCard.getImageLink() << endl;
    cout << "Display Method Prints:" << endl;
    defaultCard.display();

    cout << endl;

    cout << "*** TESTING toString METHOD :3****" << endl;
    if (defaultCard.toString() == "Name: Firewall | Description: A basic security measure to stop unnecessary connections. | Bandwidth Cost: 5 | Image Link: https://compuquip.com/hs-fs/hubfs/images/blog-images/types-of-firewalls.jpg") {
        cout << "toString Test 1 Passed!" << endl;
    }
    else {
        cout << "toString Test 1 Failed!" << endl;
    }

    if (completeCard.toString() == "Name: EternalBlue | Description: A famous exploit affecting almost all Windows Machines | Bandwidth Cost: 20 | Image Link: https://bleepstatic.com/content/posts/2017/06/07/ETERNALBLUE.jpg") {
        cout << "toString Test 2 Passed!" << endl;
    }
    else {
        cout << "toString Test 2 Failed!" << endl;
    }

    if (cardPtr->toString() == "Name: SQL Injection | Description: The 3rd most dangerous Web Security Exploit | Bandwidth Cost: 10 | Image Link: https://myrasecurity.com/assets/79302/1673879028-bedrohungen_code_injection_de_en_transparent_desktop.png") {
    }
    else {
        cout << "toString Test 3 Failed!" << endl;
    }

    cout << "*** TESTING EXPLOITCARD ***" << endl;
    ExploitCard ssrf("Server Side Request Forgery (SSRF)", 
                     "An exploit in which the attacker convinces the server to perform malicious actions",
                     10, "https://imperva.com/learn/wp-content/uploads/sites/13/2021/12/How-Server-SSRF-works.png",
                     Web, 25, 90.0 );
    ssrf.display();
    cout << endl << endl;

    cout << "*** TESTING DEFENSECARD ***" << endl;
    DefenseCard siem("Security Information and Event Management (SIEM)",
                     "A piece of software that gives a detailed live feed of events on a network",
                     30, "https://www.coresecurity.com/sites/default/files/2023-07/how-does-a-siem-work-image.png",
                     Network, 75);
    siem.display();

    cout << endl << endl;


    cout << "*** TESTING PLAYER CLASS ***" << endl;
    vector<GameCard*> deck;
    deck.push_back( new GameCard(defaultCard));
    deck.push_back(new GameCard(completeCard));
    deck.push_back(new ExploitCard(ssrf));
    deck.push_back(new DefenseCard(siem));
    Player p1(deck);

    p1.display();



    return;
}