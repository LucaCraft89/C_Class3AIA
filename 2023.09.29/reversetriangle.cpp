//
// Created by lucac on 9/29/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
        for (int i = 0; i < ((a+a)-j)-a; ++i) {
            cout << " ";
        }
        for (int i = 0; i < ((a+1)+j)-a; ++i) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
