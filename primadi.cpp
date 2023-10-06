//
// Created by lucac on 9/30/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 0; i < a*2; ++i+(++i)) {
        for (int j = 0; j < ((a-i)-j)+(a*2); ++j) {
            cout << " ";
        }
        for (int f = 0; f < i+1; ++f) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
