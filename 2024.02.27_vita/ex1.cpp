//
// Created by lucac on 2024/02/27.
//
#include <iostream>
#include <Windows.h>
#include <fstream>  
#include <string>  
#include <sstream>  

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// const int cols = 40;
const int cols = 80;
// const int rows = 11;
const int rows = 51;
const string filename = "matrix.txt";

void outMatrix(bool matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == true)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_BLUE);
            }
            cout << matrix[i][j] << " ";
            SetConsoleTextAttribute(hConsole, 0);
        }
        cout << endl;
    }
}

void initMatrix(bool matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = false;
        }
    }
}

void readMatrixFromFile(bool matrix[rows][cols], string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        for (int i = 0; i < rows && std::getline(file, line); ++i) {
            std::istringstream iss(line);
            for (int j = 0; j < cols; ++j) {
                iss >> matrix[i][j];
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}

int countActiveCells(bool matrix[rows][cols], int i, int j) {
    int count = 0;
    if (i > 0 && j > 0 && matrix[i - 1][j - 1] == true) {
        count++;
    }
    if (i > 0 && matrix[i - 1][j] == true) {
        count++;
    }
    if (i > 0 && j < cols - 1 && matrix[i - 1][j + 1] == true) {
        count++;
    }
    if (j > 0 && matrix[i][j - 1] == true) {
        count++;
    }
    if (j < cols - 1 && matrix[i][j + 1] == true) {
        count++;
    }
    if (i < rows - 1 && j > 0 && matrix[i + 1][j - 1] == true) {
        count++;
    }
    if (i < rows - 1 && matrix[i + 1][j] == true) {
        count++;
    }
    if (i < rows - 1 && j < cols - 1 && matrix[i + 1][j + 1] == true) {
        count++;
    }
    return count;
}

void evolve(bool matrix[rows][cols]) {
    bool newMatrix[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == true)
            {
                if (countActiveCells(matrix, i, j) == 2 || countActiveCells(matrix, i, j) == 3)
                {
                    newMatrix[i][j] = true;
                } else {
                    newMatrix[i][j] = false;
                }          
            } else {
                if (countActiveCells(matrix, i, j) == 3)
                {
                    newMatrix[i][j] = true;
                } else {
                    newMatrix[i][j] = false;
                }
            }
        }
    }
    
    // Copy values from newMatrix to matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

int main() {
    bool matrix[rows][cols];
    initMatrix(matrix);
    readMatrixFromFile(matrix, filename);
    outMatrix(matrix);
    while (true)
    {
        evolve(matrix);
        outMatrix(matrix);
        Sleep(0);
        cout << endl;
        cout << endl;
        cout << endl;
    }
    
    return 0;
}