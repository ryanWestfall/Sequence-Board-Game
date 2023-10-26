#include <iostream>
#include <iomanip>

#include "Game.h"



//done
void Game::title()
{
   
    cout << setw(45) << "SEQUENCE BOARD GAME\n";
    cout << setw(70) << "###################################################################\n";
    cout << setw(70) << "#    ####   ####   ####    #    #  ####  #     #    ####  ####    #\n";
    cout << setw(70) << "#   #    #  #     #    #   #    #  #     # #   #   #      #       #\n";
    cout << setw(70) << "#     #     ####  #    #   #    #  ####  #  #  #   #      ####    #\n";
    cout << setw(70) << "#   #   #   #     #    #   #    #  #     #   # #   #      #       #\n";
    cout << setw(70) << "#    ####   ####   #### #   ####   ####  #     #    ####  ####    #\n";
    cout << setw(70) << "###################################################################\n";

    cout << endl << endl;
    cout << setw(43) << "# - BLUE CHIPS\n";
    cout << setw(43) << "$ - GREEN CHIPS\n";
    cout << endl << endl;
    system("pause");
    cout << "\033[2J\033[1;1H"; //clear screen 
}

//done
void Game::mainMenu()
{     
    title();
    do
    {
        cout << setw(45) << "SEQUENCE BOARD GAME\n\n";
        cout <<setw(40) << "1. Start" << endl;
        cout << setw(40) <<"2. Rules" << endl;
        cout << setw(39) <<"3. Quit" << endl << endl;
        cout <<setw(40) <<"Choice :";
        cin >> gChoice;

        while (!isValid(gChoice, 1, 3)) // get valid input 
        {
            cout << "Please enter a number (1-3) " << endl;
            cout << "Choice : ";
            cin >> gChoice;
        }
        cout << endl;

        switch (gChoice)
        {
        case 1:
            gameLoop();
            break;
        case 2:
            rules();
            break;
        case 3:
            cout << "You have exit the game." << endl;
            break;
        defualt:
            cout << "Please enter a number (1-3)" << endl;
        }

    } while (gChoice != 3);

}

//done
void Game::rules()
{
    cout << setw(43) << "RULES" << endl;
    cout << "Number of Players : 2, 4 (groups of two), 6 (groups of three), 8 (groups of four)." << endl << endl;
    cout << "\tBoth decks must be shuffled together before games.Dealing depends on how many people are playing.Standard 2 people get 7 cards each.Depending on who goes first, you lay down a card and put a chip on the board. After putting a chip on the board, you pick up 1 card, always having 7 cards.On the board, the corners are free spots." << endl << endl;
    cout << "To Win : 2 rows of 5 chips on the board." << endl << endl << endl;
    system("pause"); //system pause to read
    cout << "\033[2J\033[1;1H"; //clear screen 
}

void Game::gameLoop()
{
    bool gameOver = false;
    Board board;
    Deck* deck = new Deck();
    deck->shuffle(); //shuffle deck

    Player p1(deck, "#");
    Player p2(deck, "$");

    p1.getCards(); // call getCards() to fill inHand list
    p2.getCards(); 

    board.displayBoard();
    string iCard;
    
    while (!gameOver)
    {
        p1.displayCards();
        cout << "Player 1 pick a card that matches on the board : "; cin >> iCard;
        p1.matchCardInHand(iCard);
        board.putChipOnBoard(iCard, p1);
        p1.getCard();
        cout << "\033[2J\033[1;1H"; //clear screen 
        board.displayBoard();
        if (board.sequenceW(p1))
        {
            gameOver = true;
            // break;
        }

        //player 2 
        p2.displayCards();
        cout << "Player 2 pick a card that matches on the board : "; cin >> iCard;
        p2.matchCardInHand(iCard);
        board.putChipOnBoard(iCard, p2);
        p2.getCard();
        cout << "\033[2J\033[1;1H"; //clear screen 
        board.displayBoard();
        if (board.sequenceW(p2))
        {
            gameOver = true;
            // break;
        }
    }
    
    delete deck;
}