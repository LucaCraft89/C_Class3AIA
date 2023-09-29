//
// Created by lucac on 9/27/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cout << "a:\n -:"; cin >> a;
    cout << "b:\n -:"; cin >> b;
    cout << "c:\n -:"; cin >> c;
    cout << "d:\n -:"; cin >> d;
    if (a>0 and !(b%2) and !(c%5) and (c>20 or c<50)) {
        cout << "Congratulzaioni hai vinto uno schiaffo\n";
    }
    return 0;
}
