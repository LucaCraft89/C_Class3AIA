//
// Created by lucac on 10/18/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a=0, in;
    cin >> in;
    for (int i = 0; i < in+2; ++i) {
        cout << "=" << " ";
    }
    cout << endl;
    for (int i = 2; i < in+2; ++i) {
        cout << "= ";
        for (int j = 0; j < i-1; ++j) {
            a = a + 1;
            cout << a << " ";
        }
        for (int f  = 0; f < (in+1)-i; ++f) {
            cout << "*" << " ";
        }
        cout << "=" << endl;
    }
    for (int i = 0; i < in+2; ++i) {
        cout << "-" << " ";
    }
    cout << endl;
    for (int i = 2; i < in+2; ++i) {
        cout << "| ";
        for (int j = 0; j < in; ++j) {
            cout << in << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < in+2; ++i) {
        cout << "-" << " ";
    }
    cout << endl;
    return 0;
}
