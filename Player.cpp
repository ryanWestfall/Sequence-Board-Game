#include "Player.h"

void Player::pTurn()
{

}

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
    if (inHand.size() != 7) // if card size not 7 dont give card 
        inHand.push_back(*deck->deal());
    else
        cout << "Already have 7 cards ";
}

//First display
void Player::displayCards()
{
    cout << " hand: \n";

    for (const auto& cards : inHand)
    {
        cout << cards << " ";
    }
    cout << endl;


} 

//RECURSIVE SORT FOR HAND 
void Player::merge(list<string>& left, list<string>& right, list<string>& result)
{
    while (!left.empty() && !right.empty())
    {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty())
    {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty())
    {
        result.push_back(right.front());
        right.pop_front();
    }
}


void Player::mergeSortHand(list<string>& hand)
{
    if (hand.size() <= 1)
        return;

    list<string> left, right;
    int middle = hand.size() / 2;

    auto it = hand.begin();
    for (int i = 0; i < middle; ++i, ++it)
    {
        left.push_back(*it);
    }

    for (; it != hand.end(); ++it)
    {
        right.push_back(*it);
    }

    mergeSortHand(left);
    mergeSortHand(right);

    hand.clear();
    merge(left, right, hand);
}


//pick a card //FIX CODE ERASE CARD IN HAND.
string Player::pickCard()
{
    bool cardFound = false;

    while (!cardFound)
    {
        cout << "Type the card in hand that matches with the board.\n";
        cout << "Card: ";
        cin >> input;

        // Check if the card is in the player's hand
        auto it = find(inHand.begin(), inHand.end(), input);

        if (it != inHand.end()) {
            // Assign the picked card to the 'card' member variable
            card = *it;
            // Erase the card from the hand
            inHand.erase(it);
            cardFound = true;
        }
        else {
            cout << "Card not found in hand!" << endl;
            card = ""; // Assign an empty string to 'card' if the card is not found
        }
    }

    return card;
}
