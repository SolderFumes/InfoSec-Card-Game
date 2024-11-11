//CS 112 Project 4, Infosec Card Game 
//https://github.com/SolderFumes/InfoSec-Card-Game
//Luka Schuller

#include "Player.h"

using namespace std;

//constructors
Player::Player() {
    playerHP = DEFAULT_PLAYER_HP;
    playerBandwidth = DEFAULT_PLAYER_BANDWIDTH;
    cardList = DEFAULT_CARD_LIST;
    cardsActive = DEFAULT_CARDS_ACTIVE;
}

Player::Player(int newHP, int newBandwidth, vector<GameCard>& newCardList) {
    playerHP = newHP;
    playerBandwidth = newBandwidth;
    cardList = newCardList;
    //cardsActive will get modified when cards are played/destroyed.
}
//DONE FOR TONIGHT