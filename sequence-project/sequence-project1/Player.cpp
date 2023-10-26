#include "Player.h"

//get 7 cards
void Player::getCards()
{
    for (int i = 0; i < 7; i++) {
        inHand.push_back(*deck->deal());
    }
}

//get 1 card  
void Player::getCard()
{
    inHand.push_back(*deck->deal());
}

//display hand
void Player::displayCards()
{
    cout << "In hand: \n";

    for (const auto& cards : inHand)
    {
        cout << cards << " ";
    }
    cout << endl;
}


//pick a card //erase in hand
string Player::matchCardInHand(const string &card)
{

    // Check if the card is in the player's hand
    auto it = find(inHand.begin(), inHand.end(), card);

    //to see if card is in hand 
    if (it != inHand.end()) {
        // erase card
        inHand.erase(it); 

        return card;
    }
    else
      cout << "Card not found in hand!" << endl;
}
