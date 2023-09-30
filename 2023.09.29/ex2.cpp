//
// Created by lucac on 9/29/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a; cin >> b;
    for (int i = 0; i < a; ++i) {
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < b-2; ++i) {
        cout << "|";
        for (int j = 0; j < a-2; ++j) {
            cout << " ";
        }
        cout << "|\n";
    }

    for (int i = 0; i < a; ++i) {
        cout << "*";
    }
    return 0;
}
