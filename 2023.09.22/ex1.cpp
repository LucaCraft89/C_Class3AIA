//
// Created by lucac on 9/22/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b, swap;
    cout << "input a:\n -:";
    cin >> a;
    cout << "input b:\n -:";
    cin >> b;
    if (a>b) {
        swap=a;
        a=b;
        b=swap;
    }
    cout << "a: " << a << "  b: " << b << "\n";
    return 0;
}
