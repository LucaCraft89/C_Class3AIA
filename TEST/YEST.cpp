//
// Created by lucac on 2024/01/19.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 100;

using namespace std;

void randomarray(string array1[MAX]) {
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        array1[i] = "";
        for (int j = 0; j < 5; j++) {
            char letter = 'A' + rand() % 26;
            array1[i] += letter;
        }
    }
}

void outarray(string array1[MAX]) {
    for (int i = 0; i < MAX; i++) {
        cout << array1[i] << endl;
    }
}

void fillarrayrandomnumbers(string array1[MAX]) {
    for (int i = 0; i < MAX; i++) {
        array1[i] = rand() % 100;
    }
}

int main() {
    string array1[MAX];
    randomarray(array1);
    outarray(array1);
    return 0;
}



