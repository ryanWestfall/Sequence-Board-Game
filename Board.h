#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Player.h"

using namespace std;

class Board
{
    const static int ROWS = 10;
    const static int COLS = 10;
    string board[ROWS][COLS] = { {"W", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "W",},   
                                 {"6C","5C","4C","3C","2C","AH","KH", "QH","10H","10S",},
                                 {"7C","AS","2D","3D","4D","5D", "6D", "7D","9H","QS",},
                                 {"8C","KS","6C","5C","4C","3C","2C","8D","8H","KS",},
                                 {"9C","QS","7C","6H","5H","4H","AH","9D","7H","AS",},
                                 {"10C","10S","8C","7H","2H","3H","KH","10D","6H","2D",},
                                 {"QC","9S","9C","8H","9H","10H","QH","QD","5H","3D",},
                                 {"KC","8S","10C","QC","KC","AC","AD","KD","4H","4D",},
                                 {"AC","7S","6S","5S","4S","3S","2S","2H","3H","5D",},
                                 {"W","AD","KD","QD","10D","9D","8D","7D","6D","W"}
    };

    string rChip;

public:
    Board() {}
    ~Board() {}
    int getRows() const { return ROWS; }
    int getCols() const { return COLS; }
    void displayBoard();
    void putChipOnBoard(string, Player &p);
    void removeChip(Player&);
    void addChip(Player&);
    bool sequenceW(Player& p);
};