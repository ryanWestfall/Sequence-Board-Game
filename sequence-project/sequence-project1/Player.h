#pragma once
//Player class
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Deck.h"

using namespace std;

class Player
{
    list <string> inHand; //cards in hand
    Deck* deck; //deck pointer 
    string input; //chose for spot
    string card; //

public:
    string chip; //players chips
    Player(Deck* d, string c) : deck(d), chip(c) {}
    ~Player() {} 

    void getCards(); // get 7 cards in hands begining of game
    void getCard(); //get card after turn
    void displayCards(); //display players card 
    
    string matchCardInHand(const string&); //see if card matches with board
};
