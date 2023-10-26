#pragma once

#include "Deck.h"
#include "Board.h"
#include "Player.h"


class Game
{
    int gChoice = 0;
    
public:
    void title();
    void mainMenu();
    void rules();
    void gameLoop();
    bool isValid(int num, int min, int max)  
    {
        if (num < min || num > max) 
            return false;
        else
            return true;
    }
};