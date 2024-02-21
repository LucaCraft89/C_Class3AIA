//
// Created by lucac on 2024/02/19.
//
#include <iostream>

using namespace std;

const int RIGHE = 6;
const int COLONNE = 7;
const char EMPTY = '.';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void printGrid(char grid[RIGHE][COLONNE])
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            cout << "| " << grid[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "--1---2---3---4---5---6---7--"
         << "\n\n";
}

void initializeGrid(char grid[RIGHE][COLONNE])
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            grid[i][j] = EMPTY;
        }
    }
}

bool newCheckWin(char grid[RIGHE][COLONNE], char player, int col, int row)
{
    for (int j = 0; j < COLONNE - 3; j++)
    {
        if (grid[row][j] == player && grid[row][j + 1] == player && grid[row][j + 2] == player && grid[row][j + 3] == player)
        {
            return true;
        }
    }


    for (int j = 0; j < RIGHE - 3; j++)
    {
        if (grid[j][col] == player && grid[j + 1][col] == player && grid[j + 2][col] == player && grid[j + 3][col] == player)
        {
            return true;
        }
    }
    

    for (int i = col; i < col+3; i++)
    {
        for (int j = row; j < row+3; j++)
        {
            if (grid[j][i] == player && grid[j + 1][i + 1] == player && grid[j + 2][i + 2] == player && grid[j + 3][i + 3] == player)
            {
                return true;
            }
        }
    }

    for (int i = col-3; i >= col; i--)
    {
        for (int j = row-3; j >= row; j--)
        {
            if (grid[j][i] == player && grid[j + 1][i + 1] == player && grid[j + 2][i + 2] == player && grid[j + 3][i + 3] == player)
            {
                return true;
            }
        }
    }
    
    for (int i = col; i < col+3; i++)
    {
        for (int j = row; j >= row-3; j--)
        {
            if (grid[j][i] == player && grid[j - 1][i + 1] == player && grid[j - 2][i + 2] == player && grid[j - 3][i + 3] == player)
            {
                return true;
            }
        }
    }

    for (int i = col-3; i < col; i++)
    {
        for (int j = row; j < row+4; j++)
        {
            if (grid[j][i] == player && grid[j - 1][i + 1] == player && grid[j - 2][i + 2] == player && grid[j - 3][i + 3] == player)
            {
                return true;
            }
        }
    }
    return false;
}

int inputColumn(char grid[RIGHE][COLONNE], int column, char player)
{
    for (int i = RIGHE - 1; i >= 0; i--)
    {
        if (grid[i][column] == EMPTY)
        {
            grid[i][column] = player;
            return i;
        }
    }
    cout << "=============================\n       Column " << column + 1 << " is full\n=============================\n"
         << endl;
    return -1;
}

void winMsg(int player)
{
    if (player==3){
        cout << "It's a draw!" << endl;
        return;
    }
    cout << "Player " << player << " wins!" << endl;
}

bool fullGrid(char grid[RIGHE][COLONNE])
{
    for (int i = 0; i < COLONNE; i++)
    {
        if (grid[0][i] == EMPTY)
        {
            return false;
        }
    }
    return true;
}

int input(char grid[RIGHE][COLONNE]){
    int column = 0, row = 0;
    if (fullGrid(grid))
    {
        return 3;
    }
    if (newCheckWin(grid, PLAYER2, column-1, row))
    {
        return 2;
    }
    printGrid(grid);
    do
    {
        do
        {
            cout << "Input Column Player 1\n -:";
            cin >> column;
            cout << endl;
        } while (column < 1 || column > 7);
        row = inputColumn(grid, column - 1, PLAYER1);
        printGrid(grid);
    } while (row==-1);
    if (newCheckWin(grid, PLAYER1, column-1, row))
    {
        return 1;
    }
    do
    {
        do
        {
            cout << "Input Column Player 2\n -:";
            cin >> column;
            cout << endl;
        } while (column < 1 || column > 7);
        row = inputColumn(grid, column - 1, PLAYER2);
        printGrid(grid);
    } while (row==-1);
    return 0;
}

int main()
{
    char grid[RIGHE][COLONNE];
    int win=0;
    initializeGrid(grid);
    do
    {
        win = input(grid);
    } while (win == 0);
    winMsg(win);
    return 0;
}