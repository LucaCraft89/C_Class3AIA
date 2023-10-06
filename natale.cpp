//
// Created by lucac on 9/30/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a; int l;
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
    for (int j = 0; j < ((a)-(a-1))+a; ++j) {
        cout << " ";
    }
    for (l = 0; l < a; ++l+(++l)) {
        cout << "*";
    }
    cout << "\n";
    for (int i = 0; i < (a+1)*2; ++i+(++i)) {
        for (int j = 0; j < (((a+1)-i)-j)+(a); ++j) {
            cout << " ";
        }
        for (int f = l; f < i+1; ++f) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
