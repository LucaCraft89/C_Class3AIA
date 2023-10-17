//
// Created by lucac on 10/17/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string bin;
    char temp;
    int inter=0;
    cout << "immettere bin (non più di 8 bit)\n -:";
    fflush(stdin);
    getline(cin, bin);

    for ( int jj = 0, j = 8 - 1; jj < 8/2; jj++, j--)
    {
        temp = bin[jj];
        bin[jj] = bin[j];
        bin[j] = temp;
    }


    for (int i = 0; i < 8; ++i) {
        if (bin[i-1]=='1'){
            inter = inter + pow(2, i-1);
        }
    }
    if (bin[7]=='1'){
        inter = inter + pow(2, 7);
    }
    cout << inter << endl;

    return 0;
}
