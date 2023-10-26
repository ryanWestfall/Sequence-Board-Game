#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Deck.h"

using namespace std;

class Player
{
    list <string> inHand;
    Deck* deck;
    string input; //chose for spot
    string card;

public:
    string chip;
    Player(Deck* d, string c) : deck(d), chip(c) {}
    ~Player() {}

    void getCards();
    void getCard();
    void displayCards();
    
    string matchCardInHand(const string&);
};