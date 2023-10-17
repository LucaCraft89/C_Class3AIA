//
// Created by lucac on 10/16/2023.
//
#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i < 100; i+=2) {
        cout << i << "\t";
        if (!((i+1)%5)){
            cout << endl;
        }
    }
    return 0;
}
