//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller
#ifndef DEFENSECARD_H
#define DEFENSECARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "GameCard.h"

using namespace std;

//named constants
const int DEFAULT_CARD_HEALTH = 50;

class DefenseCard : public GameCard {
    public:
    //CONSTRUCTORS
    DefenseCard();
    DefenseCard(string, string, int, string, AttackSurface, int);

    //GETTER
    int getCardHealth() const;
    
    //SETTER
    void setCardHealth(int);
    int reduceCardHealth(int reduceBy); //return the difference between cardHealth
    // and reduceby, therefore finding if theres any leftover damage :)

    //OTHER METHODS
    virtual void display() const override;
    virtual string toString() const override;

    private:
    int cardHealth;
};




#endif /* DEFENSECARD_H */