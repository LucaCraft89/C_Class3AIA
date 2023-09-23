//
// Created by lucac on 9/22/2023.
//
#include <iostream>

using namespace std;

int main() {
    float a;
    cout << "input a:\n -:";
    cin >> a;
    if (a>0) {
        cout << a << " is positive";
    }
    else if (a<0) {
        cout << a << " is negative";
    }
    else {
        cout << a << " is neutral aka 0";
    }
    return 0;
}
