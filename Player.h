#pragma once
#include <iostream>
#include <string>
#include <list>

#include "Deck.h"

using namespace std;

class Player
{
    list <string> inHand;
    Deck* deck;
    string input; //chose for spot
    string card;
    bool cardFound = false;

public:
    string chip;
    Player(Deck* d, string c) : deck(d), chip(c) {}
    ~Player() {}

    void pTurn();
    void getCards();
    void getCard();
    void displayCards();
    string pickCard();
    void merge(list<string>& left, list<string>& right, list<string>& result);
    void mergeSortHand(list<string>& hand);
};