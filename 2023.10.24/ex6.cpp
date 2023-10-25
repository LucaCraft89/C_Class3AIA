//
// Created by lucac on 10/24/2023.
//x
#include <iostream>

using namespace std;

int main() {
    int pok;
    string frase, parola;
    fflush(stdin);
    getline(cin, frase);
    fflush(stdin);
    getline(cin, parola);
    for (int i = 0; i < frase.size()+1; i++) {
        if (frase[i]==parola[0]){
            for (int j = 0; j < parola.size()+1; j++) {
                if (frase[i+j]==parola[j]){
                    pok=1;
                    for (int k = 0; k < parola.size()+1; ++k) {
                        frase[i+k] = ' ';
                    }
                }
                else {
                    pok=0;
                    break;
                }
            }
        }
        if (pok==1){
            cout << frase << endl;
            break;
        }
    }
    cout << pok;
    return 0;
}
