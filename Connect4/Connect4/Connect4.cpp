#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
 * Connect 4 Project-1
 */

class Player
{
public:
    string piece;
    string name;

    Player(string p, string n) : piece(p), name(n) {}
};

class Game
{
    int pCol = 0;
    bool gameOver = false;

public:
    void titleDisplay();
    void displayBoard(string board[][7], int rows, int cols);
    void putPieceInColumn(string board[][7], Player& p, int rows, int col);
    void gameLoop(string board[][7], Player& p1, Player& p2, int rows, int cols);
    bool isWinner(string board[][7], Player player, int rows, int cols);
};
void Game::titleDisplay()
{
    cout << setw(61) << "Connect 4 Board Game\n";
    cout << setw(80) << "#################################################################\n";
    cout << setw(80) << "#  #####  ####   #    #  #    #  #####   #####  ######    #   # #\n";
    cout << setw(80) << "# #      #    #  ##   #  ##   #  #      #         #       #   # #\n";
    cout << setw(80) << "# #      #    #  # #  #  # #  #  #####  #         #       ##### #\n";
    cout << setw(80) << "# #      #    #  #   ##  #   ##  #      #         #           # #\n";
    cout << setw(80) << "#  #####  ####   #    #  #    #  #####   #####    #           # #\n";
    cout << setw(80) << "#################################################################\n";
    cout << endl;


    cout << setw(54) << "$- Player 1\n";
    cout << setw(54) << "@ - Player 2\n";

    system("pause");
    cout << "\033[2J\033[1;1H";
}
void Game::putPieceInColumn(string board[][7], Player& p, int rows, int col)
{
    for (int row = rows; row >= 0; row--)
    {
        if (board[row][col - 1] == "*")
        {
            board[row][col - 1] = p.piece;
            break;
        }
    }
}
void Game::gameLoop(string board[][7], Player& p1, Player& p2, int rows, int cols)
{
    //display board
    displayBoard(board, rows, cols);

    while (!gameOver)
    {
        cout << endl;
        cout << setw(40) << p1.name << ", choose a column (1-7): "; cin >> pCol;
        putPieceInColumn(board, p1, rows, pCol);
        cout << "\033[2J\033[1;1H";
        displayBoard(board, rows, cols);
        if (isWinner(board, p1, rows, cols))
        {
            cout << p1.name << " wins!" << endl;
            gameOver = true;
            break;
        }

        //player 2's turn
        cout << setw(40) << p2.name << ", choose a column (1-7): ";
        cin >> pCol;
        putPieceInColumn(board, p2, rows, pCol);
        cout << "\033[2J\033[1;1H";
        displayBoard(board, rows, cols);
        if (isWinner(board, p2, rows, cols))
        {
            cout << p2.name << " wins!" << endl;
            gameOver = true;
            break;
        }
    }
}
bool Game::isWinner(string board[][7], Player player, int rows, int cols)
{
    // Check for horizontal four-in-a-row
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col <= cols - 4; col++)
        {
            if (board[row][col] == player.piece &&
                board[row][col + 1] == player.piece &&
                board[row][col + 2] == player.piece &&
                board[row][col + 3] == player.piece)
            {
                return true;
            }
        }
    }

    // Check for vertical four-in-a-row
    for (int row = 0; row <= rows - 4; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == player.piece &&
                board[row + 1][col] == player.piece &&
                board[row + 2][col] == player.piece &&
                board[row + 3][col] == player.piece)
            {
                return true;
            }
        }
    }

    // Check for diagonal down-right four-in-a-row
    for (int row = 0; row <= rows - 4; row++)
    {
        for (int col = 0; col <= cols - 4; col++)
        {
            if (board[row][col] == player.piece &&
                board[row + 1][col + 1] == player.piece &&
                board[row + 2][col + 2] == player.piece &&
                board[row + 3][col + 3] == player.piece)
            {
                return true;
            }
        }
    }

    // Check for diagonal down-left four-in-a-row
    for (int row = 0; row <= rows - 4; row++)
    {
        for (int col = 3; col < cols; col++)
        {
            if (board[row][col] == player.piece &&
                board[row + 1][col - 1] == player.piece &&
                board[row + 2][col - 2] == player.piece &&
                board[row + 3][col - 3] == player.piece)
            {
                return true;
            }
        }
    }

    // If no such patterns of four identical elements found in the matrix, return false
    return false;
}
void Game::displayBoard(string board[][7], int rows, int cols)
{
    cout << setw(61) << "Connect 4 Board Game\n";
    for (int row = 0; row < rows; row++)
    {
        cout << setw(40) << "#";
        for (int col = 0; col < cols; col++)
        {
            cout << setw(2) << board[row][col] << " ";
        }
        cout << "#" << endl;
    }
    cout << setw(62) << "#######################" << endl;

    cout << setw(40) << " ";
    for (int i = 1; i <= 7; i++)
    {
        cout << setw(2) << i << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    const int rows = 6;
    const int cols = 7;
    Player p1("$", "Player 1");
    Player p2("@", "Player 2");
    Game game;
    string board[rows][cols] =
    {
      {"*", "*", "*", "*", "*", "*", "*"},
      {"*", "*", "*", "*", "*", "*", "*"},
      {"*", "*", "*", "*", "*", "*", "*"},
      {"*", "*", "*", "*", "*", "*", "*"},
      {"*", "*", "*", "*", "*", "*", "*"},
      {"*", "*", "*", "*", "*", "*", "*"}
    };

    //display title
    game.titleDisplay();

    game.gameLoop(board, p1, p2, rows, cols);

    return 0;
}