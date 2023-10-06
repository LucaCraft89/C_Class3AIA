//
// Created by lucac on 10/4/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "inserire a >0 e compreso da 1 a 10\n -:";
    cin >> a;
    while (a<0 or a < 1 or a > 10) {
        cout << "il numero non soddisfa i requisito\n";
        cout << "inserire a >0 e compreso da 1 a 10\n -:";
        cin >> a;
    }
    return 0;
}
