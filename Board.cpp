#include "Board.h"

//display board 
void Board::displayBoard()
{
   cout << setw(61) << "+---------------------------------------------------+" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        cout << setw(10) << right << "| ";
        for (int j = 0; j < COLS; ++j)
        {
          cout << setw(3) << board[i][j] << "  ";
        }
        cout << "|" << endl;
    }
   cout << setw(61) << "+---------------------------------------------------+" << endl;
}

void Board::putChipOnBoard(string card, Player &p)
{
    int choice = 0;

    bool found = false;
    int matchCount = 0;
    int matchRow[2] = { -1, -1 };
    int matchCol[2] = { -1, -1 };
    // Find the matching cards on the board for the selected card
 
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == card)
            {
                matchRow[matchCount] = i;
                matchCol[matchCount] = j;
                matchCount++;
            }
        }
    }

    if (matchCount == 2)
    {
        found = true;

        // Prompt the user to choose which card to swap
        cout << "There are two spots the same on the board, choose (1) or (2): ";
        cin >> choice;

        // Swap the chosen card with the chip           
        if (choice == 1)
        {
            board[matchRow[0]][matchCol[0]] = p.chip;
        }
        else if (choice == 2)
        {
            board[matchRow[1]][matchCol[1]] = p.chip;
        }
        matchCount--;
    }
    else
    {
        found = true;

        // Find the next matching card and swap it with the chip
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {

                if (board[i][j] == card)
                {
                    board[i][j] = p.chip;
                    break;
                }
            }
        }
    }

    if (!found)
    {
        cout << "Sorry, no matching cards found on the board." << endl;
    }
}

//if JH or JD remove string symbol
void Board::removeChip()
{
        cout << "Type what chip you want to remove." << endl;
      //  cout << "Chip : ";  cin >> rChip; cout << endl;
      // if 2 on board
      // cout << " The first one or second one (1) or (2)
        //take the original board copy everthing else but the card that chip is beening removed. 
}

//done
//see if there is an sequence on the board
bool Board::sequenceW(Player& p)
{
    //check for horizontal for sequence 5 in a row or a wild spot
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j <= COLS - 5; j++)
        {
            if ((board[i][j] == "W" || board[i][j] == p.chip) &&
                board[i][j + 1] == p.chip &&
                board[i][j + 2] == p.chip &&
                board[i][j + 3] == p.chip &&
                board[i][j + 4] == p.chip)
            {
                return true;
            }
        }
    }
    //check for vertical 
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i <= ROWS - 5; i++)
        {
            if ((board[i][j] == "W" || board[i][j] == p.chip) &&
                board[i + 1][j] == p.chip &&
                board[i + 2][j] == p.chip &&
                board[i + 3][j] == p.chip &&
                board[i + 4][j] == p.chip)
            {
                return true;
            }
        }
    }
    //check diagonal left to right down
    for (int i = 0; i <= ROWS - 5; i++)
    {
        for (int j = 0; j <= COLS - 5; j++)
        {
            if ((board[i][j] == "W" || board[i][j] == p.chip) &&
                board[i + 1][j + 1] == p.chip &&
                board[i + 2][j + 2] == p.chip &&
                board[i + 3][j + 3] == p.chip &&
                board[i + 4][j + 4] == p.chip)
            {
                return true;
            }
        }
    }
    //check diagonal right to left down
    for (int i = 0; i <= ROWS - 5; i++)
    {
        for (int j = COLS - 1; j >= 4; j--)
        {
            if ((board[i][j] == "W" || board[i][j] == p.chip) &&
                board[i + 1][j - 1] == p.chip &&
                board[i + 2][j - 2] == p.chip &&
                board[i + 3][j - 3] == p.chip &&
                board[i + 4][j - 4] == p.chip)
            {
                return true;
            }
        }
    }
    return false;
}