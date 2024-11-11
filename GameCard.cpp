//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#include "GameCard.h"

using namespace std;

//CONSTRUCTORS
GameCard::GameCard() {
    cardName = DEFAULT_NAME;
    cardDescription = DEFAULT_DESCRIPTION;
    bandwidthCost = DEFAULT_BANDWIDTH_COST;
    imageLink = DEFAULT_IMAGE_LINK;
    attackSurface = DEFAULT_ATTACK_SURFACE;
}

GameCard::GameCard(string newName, string newDescription,
                   int newBandwidthCost, string newImageLink, AttackSurface newAttackSurface) {
                    cardName = newName;
                    cardDescription = newDescription;
                    bandwidthCost = newBandwidthCost;
                    imageLink = newImageLink;
                    attackSurface = newAttackSurface;
                   }

//GETTERS

string GameCard::getCardName() const { return cardName; }

string GameCard::getCardDescription() const { return cardDescription; }

int GameCard::getBandwidthCost() const { return bandwidthCost; }

string GameCard::getImageLink() const { return imageLink; }

AttackSurface GameCard::getAttackSurface() const { return attackSurface; }

//SETTERS

void GameCard::setCardName(string newName) { cardName = newName; }

void GameCard::setCardDescription(string newDescription) { cardDescription = newDescription; }

void GameCard::setBandwidthCost(int newBandwidthCost) { 
    //data validation!
    if (newBandwidthCost >= 0) {
        bandwidthCost = newBandwidthCost; 
    }
    else {
        cout << "Invalid Bandwidth Cost!" << endl;
    }
}

void GameCard::setImageLink(string newImageLink) { 
    //perform some data validation using regular expressions
    //to determine if the argument is a valid URL.
    //                                  vv This "R" is used to turn the regex sequence into a "raw" string.
    //                                      This allows us to avoid weird escape sequence shenanigans
    if (regex_match (newImageLink, regex( R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)" ))) {
        imageLink = newImageLink;
    }
    else {
        cout << "Invalid Image Link." << endl;
    }
}

void GameCard::setAttackSurface(AttackSurface newAttackSurface) { attackSurface = newAttackSurface; }

//OTHER METHODS
void GameCard::display() const {
    cout << getCardName() << ": " << getCardDescription() << ". Costs " << getBandwidthCost()
         << " bandwidth. Image is stored at " << getImageLink() 
         << ". Attack surface is " << attackSurfaceNames[getAttackSurface()] << "."; 
}

string GameCard::toString() const {
    string returnString = "Name: " + getCardName();
    returnString += " | Description: " + getCardDescription();
    returnString += " | Bandwidth Cost: " + to_string(getBandwidthCost());
    returnString += " | Image Link: " + getImageLink();
    returnString += " | Attack Surface: " + attackSurfaceNames[getAttackSurface()];

    return returnString;
}