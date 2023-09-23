//
// Created by lucac on 9/23/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, i=20, j, jj, temp;
    int bin[20];
    cin >> a;
    for (int i = 0; i < 20; ++i) {
        if (a%2){
            bin[i]=1;
            a=a/2;
        }
        else {
            bin[i]=0;
            a=a/2;
        }
    }
    for ( jj = 0, j = 20 - 1; jj < 20/2; jj++, j--)
    {
        temp = bin[jj];
        bin[jj] = bin[j];
        bin[j] = temp;
    }
    for (int f = 0; f < 20; ++f) {
        cout << bin[f];
    }
    return 0;
}
