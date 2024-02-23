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

//IF JH or JD REMOVE STRING VARIBLE
void Board::removeChip(Player& p)
{
    cout << "Enter the spot where you want to remove your chip: ";
    cin >> spot;
    cout << endl;

    auto it = originalSpots.find(p.chip);
    if (it != originalSpots.end())
    {
        const string& originalSpot = it->first;
        int chipRow = -1;
        int chipCol = -1;

        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                if (board[i][j] == p.chip)
                {
                    chipRow = i;
                    chipCol = j;
                    break;
                }
            }

            if (chipRow != -1 && chipCol != -1)
            {
                break;
            }
        }

        if (chipRow != -1 && chipCol != -1)
        {
            board[chipRow][chipCol] = originalSpot; // Replace the chip with its original spot
            originalSpots.erase(it); // Remove the chip from the original spots data structure
        }
    }
    else
    {
        cout << "Chip " << p.chip << " does not have an original spot." << endl;
    }
}

void Board::addChip(Player& p)
{
    cout << "Type what spot you want on the board: ";
    cin >> spot;

    bool found = false;
    int matchCount = 0;
    int matchRow[2] = { -1, -1 };
    int matchCol[2] = { -1, -1 };


    // Find the matching cards on the board for the selected card
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == spot)
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
        int choice;
        cout << "There are two spots the same on the board. Choose (1) or (2): ";
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
        matchCount--; //one less match now 
    }
    else
    {
        found = true;

        // Find the next matching card and swap it with the chip
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                if (board[i][j] == spot)
                {
                    board[i][j] = p.chip;
                    break;
                }
            }
        }
    }

    if (!found)
    {
        cout << "Sorry, that spot is taken.." << endl;
    }
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