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

//OTHER METHODS
void DefenseCard::display() {
    GameCard::display();
    cout << " This card has " << cardHealth << " health.";
}

string DefenseCard::toString() {
    string resultString = GameCard::toString();
    resultString += " | Health: " + cardHealth;

    return resultString;
}