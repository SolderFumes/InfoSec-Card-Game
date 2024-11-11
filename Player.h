//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "ExploitCard.h"
#include "DefenseCard.h"
#include <vector>

using namespace std;

//named constants
const int DEFAULT_PLAYER_HP = 250;
const int DEFAULT_PLAYER_BANDWIDTH = 50;
const vector<GameCard> DEFAULT_CARD_LIST;
const vector<GameCard> DEFAULT_CARDS_ACTIVE;

class Player {
    public:
    //constructors
    Player();
    Player(int, int, vector<GameCard>&);

    //getters
    int getPlayerHP() const;
    int getPlayerBandwidth() const;
    vector<GameCard>& getPlayerCardList();
    vector<GameCard>& getPlayerCardsActive();

    //setters
    void setPlayerHP(int newHP);
    void setPlayerBandwidth(int newBandwidth);
    void addCard(GameCard);
    void playCard(GameCard);


    private:
    int playerHP;
    int playerBandwidth; //mana
    vector<GameCard> cardList;
    vector<GameCard> cardsActive;
};


#endif /* PLAYER_H */