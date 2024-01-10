//
// Created by lucac on 11/29/2023.
//
#include <iostream>
#include "inpi.h"

using namespace std;

void hang(int state){
    switch (state) {
        case 0:
            hang0();
            break;
        case 1:
            hang1();
            break;
        case 2:
            hang2();
            break;
        case 3:
            hang3();
            break;
        case 4:
            hang4();
            break;
        case 5:
            hang5();
            break;
        case 6:
            hang6();
            break;
        default:
            cout << "ehe?";
    }
}

int main() {
    string word;
    char guess;
    int state=0, letters[200], f=0, n=0;
    for (int i = 0; i < size(letters); i++) {
        letters[i]=-1;
    }
    cout << "Immettere parola\n -:";
    fflush(stdin);
    getline(cin, word);
    for (int i = 0; i < 7; i++) {
        hang(state);
        cout << word[0] << " ";
        f=0;
        for (int j = 1; j < word.length(); j++) {
            if (j==letters[j]){
                cout << word[j]<< " ";
                f++;
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        if (f+1 == word.length()){
            cout << "hai vinto!!!\n";
            return 1;
        }
        cout << "immettre lettera\n -:";
        cin >> guess;
        for (int j = 1; j < word.length(); j++) {
            if (guess==word[j]){
                letters[j]=j;
                state=0;
                n=0;
            } else {
                n=1;
            }
        }
        if (n==1){
            state++;
        }
    }
    cout << "hai preso||\n";
    return 0;
}
