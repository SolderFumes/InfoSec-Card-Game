//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller
#ifndef GAMECARD_H
#define GAMECARD_H


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

enum AttackSurface {SocialEngineering, DoS, Web, Network};
const string attackSurfaceNames[] {"Social Engineering", "DoS", "Web", "Network"};

const string DEFAULT_NAME = "NoName";
const string DEFAULT_DESCRIPTION = "NoDescription";
const int DEFAULT_BANDWIDTH_COST = 1;
const string DEFAULT_IMAGE_LINK = "https://c.stocksy.com/a/RQY500/z9/1323975.jpg";
const AttackSurface DEFAULT_ATTACK_SURFACE = SocialEngineering;

class GameCard {
    public: 
    //CONSTRUCTORS
    GameCard(); //sets all private members to default values
    GameCard(string, string, int, string, AttackSurface); //initializes all 3 private members
    
    //GETTERS
    string getCardName() const;
    string getCardDescription() const;
    int getBandwidthCost() const;
    string getImageLink() const;
    AttackSurface getAttackSurface() const;
    
    //SETTERS
    void setCardName(string);
    void setCardDescription(string);
    void setBandwidthCost(int);
    void setImageLink(string);
    void setAttackSurface(AttackSurface);

    //OTHER METHODS
    // void displayImage(); //will display card image in a new window (MAY NEED SEPERATE CLASS AND OPENCV SO I WILL DO THIS LATER ALONG WITH GUI)
    virtual void display() const;
    virtual string toString() const;

    protected:
    string cardName;
    string cardDescription;
    int bandwidthCost;
    string imageLink;
    AttackSurface attackSurface;


};

#endif /* GAMECARD_H */