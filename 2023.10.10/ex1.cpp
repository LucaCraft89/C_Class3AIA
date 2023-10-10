//
// Created by lucac on 10/10/2023.
//
#include <iostream>

using namespace std;

int main() {
    char a, b;
    for (int i = 0; i < 26; ++i) {
        a = i + 'a';
        b = i + 'A';
        cout << a << ": " << i << "\t" << b << ": " << i << endl;
    }
    cout << endl;

    return 0;
}
