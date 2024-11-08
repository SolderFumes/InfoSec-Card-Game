//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller
#ifndef GAMECARD_H
#define GAMECARD_H


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string DEFAULT_NAME = "NoName";
const string DEFAULT_DESCRIPTION = "NoDescription";
const int DEFAULT_BANDWIDTH_COST = 1;
const string DEFAULT_IMAGE_LINK = "https://c.stocksy.com/a/RQY500/z9/1323975.jpg";

class GameCard {
    public: 
    //CONSTRUCTORS
    GameCard(); //sets all private members to default values
    GameCard(string, string, int, string); //initializes all 3 private members
    
    //GETTERS
    string getCardName() const;
    string getCardDescription() const;
    int getBandwidthCost() const;
    string getImageLink() const;
    
    //SETTERS
    void setCardName(string);
    void setCardDescription(string);
    void setBandwidthCost(int);
    void setImageLink(string);

    //OTHER METHODS
    // void displayImage(); //will display card image in a new window (MAY NEED SEPERATE CLASS AND OPENCV SO I WILL DO THIS LATER ALONG WITH GUI)
    void display() const;
    string toString() const;

    protected:
    string cardName;
    string cardDescription;
    int bandwidthCost;
    string imageLink;


};

#endif /* GAMECARD_H */