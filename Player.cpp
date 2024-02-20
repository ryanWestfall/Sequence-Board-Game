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
