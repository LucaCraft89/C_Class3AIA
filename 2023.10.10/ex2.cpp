//
// Created by lucac on 10/10/2023.
//
#include <iostream>

using namespace std;

int main() {
    char a;
    int n;
    cout << "N:\n -:"; cin >> n;
    cout << "a:\n -:"; cin >> a;
    char b=a;
    a = 'a' + ((a-'a' + n) % 26);
    cout << a  << endl;
    cout << endl;

    return 0;
}
