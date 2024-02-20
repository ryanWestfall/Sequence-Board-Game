#include <iostream>
#include <list>
#include <ctime>
#include<cstdlib>
#include <algorithm>

#include "Deck.h"

Deck::Deck() {
    cards = { "JC", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
    "JS","6C","5C","4C","3C","2C","AH","KH", "QH","10H","10S" ,
    "7C","AS","2D","3D","4D","5D", "6D", "7D","9H","QS" ,
    "8C","KS","6C","5C","4C","3C","2C","8D","8H","KS" ,
     "9C","QS","7C","6H","5H","4H","AH","9D","7H","AS" ,
     "10C","10S","8C","7H","2H","3H","KH","10D","6H","2D" ,
     "QC","9S","9C","8H","9H","10H","QH","QD","5H","3D" ,
     "KC","8S","10C","QC","KC","AC","AD","KD","4H","4D" ,
     "AC","7S","6S","5S","4S","3S","2S","2H","3H","5D" ,
     "JD","AD","KD","QD","10D","9D","8D","7D","6D","JH",
    "JH", "JD","JC", "JS" };
}

void Deck::shuffle()
{
    // Seed the random number generator
    srand(time(0));

    // Shuffle the list using the rand() function
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        auto dist = distance(cards.begin(), it);
        auto rand_idx = rand() % (cards.size() - dist) + dist;
        iter_swap(it, next(cards.begin(), rand_idx));
    }
}

void Deck::display()
{
    cout << "In Deck : " << endl;
    for (auto& x : cards)
    {
        cout << x << endl;
    }
    cout << endl << endl;
}

void Deck::deleteCard(const string& card)
{
    // Find the card in the list
    auto it = find(cards.begin(), cards.end(), card);

    if (it != cards.end()) {
        // Erase the card from the list
        cards.erase(it);
    }
    else {
        cout << "Card not found in the deck!" << endl;
    }
}

string* Deck::deal()
{
    string* tCard = new string(cards.front());
    cards.pop_front();
    return tCard;
}