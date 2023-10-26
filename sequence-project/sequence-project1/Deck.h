#pragma once
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Deck
{
private:
    list<string>cards;
    list<string>::iterator it;

public:
    Deck();
    ~Deck() {}

    void shuffle();
    void display();
    void deleteCard(const string& card);
    string* deal();
};