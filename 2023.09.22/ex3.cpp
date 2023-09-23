//
// Created by lucac on 9/22/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Input a:\n -:";
    cin >> a;
    cout << "Input b:\n -:";
    cin >> b;
    cout << "Input c:\n -:";
    cin >> c;
    if (a<b and b<c and c>a) {
        cout << "The inserted numbers make a pitagoric tern";
    }
    else {
        cout << "The inserted numbers DO NOT make a pitagoric tern";
    }
    return 0;
}
