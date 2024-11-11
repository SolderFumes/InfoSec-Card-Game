//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#include "DefenseCard.h"

using namespace std;

//constructors :
DefenseCard::DefenseCard() : GameCard() {
    cardHealth = DEFAULT_CARD_HEALTH;
}

DefenseCard::DefenseCard(string newName, string newDescription, int newBandwidthCost,
                         string newImageLink, AttackSurface newAttackSurface, int newHealth) :
                         GameCard(newName, newDescription, newBandwidthCost, newImageLink, newAttackSurface) {
                            cardHealth = newHealth;
                         }

//GETTER
int DefenseCard::getCardHealth() const { return cardHealth; }

//SETTER
void DefenseCard::setCardHealth(int newHealth) { cardHealth = newHealth; }

int DefenseCard::reduceCardHealth(int reduceBy) {
    int difference = cardHealth - reduceBy; //<-- returns a negative value if there
    //is leftover damage.
    cardHealth -= reduceBy;
    return difference;
}

//OTHER METHODS
void DefenseCard::display() const {
    GameCard::display();
    cout << " This card has " << cardHealth << " health.";
}

string DefenseCard::toString() const {
    string resultString = GameCard::toString();
    resultString += " | Health: " + to_string(cardHealth);

    return resultString;
}