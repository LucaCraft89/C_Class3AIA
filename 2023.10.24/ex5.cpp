//
// Created by lucac on 10/24/2023.
//
#include <iostream>

using namespace std;

int main() {
    string frase, accumulatore;
    int parole;
    fflush(stdin);
    getline(cin, frase);
    for (int j = 0; j < frase.size()+1; j++) {
        if (frase[j]==' ' or frase[j]=='.' or frase[j]==',' or frase[j]==';'){
           cout << endl;
        }else{
           cout << frase[j];
        }
    }


    return 0;
}
