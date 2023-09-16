//
// Created by lucac on 9/16/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a=2, b=3, tmp;
    cout << " a" << " | " << "b" << "\n";
    cout << "-------" << "\n";
    cout << " "<< a << " | " << b << "\n";
    tmp=a; a=b; b=tmp;
    cout << " "<< a << " | " << b << "\n";
    return 0;
}
