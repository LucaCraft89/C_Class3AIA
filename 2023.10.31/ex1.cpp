//
// Created by lucac on 10/31/2023.
//
#include <iostream>
#include <ctime>

using namespace std;

void Es1(){
    int numero, input;
    srand(time(NULL));
    numero = rand()%10000;
    do{
        cout << "inseriscilo sto nuemro\n";
        cin >> input;
        if (input < numero){
            cout << "il numero se più grande\n";
        } else {
            cout << "il numero se più picol\n";
        }
    } while (numero!=input);
}

void Es2(){
    int semiCiotola, p1;
    cout << "Puntata P1\n"; cin >> p1;
    srand(time(NULL));
    semiCiotola = rand()%32000;
    do {
        semiCiotola = semiCiotola -5;
    } while (semiCiotola > 5);
    if (semiCiotola==5){
        cout << "vince il banco\n";
    } else {
        cout << "l'angolo vincente: " << semiCiotola << endl;
    }
}

void Es3(){
    int numero, lanci, pariDispari;
    cout << "pari o dispari (pari, 0 , dispari, 1)\n";
    cin >> pariDispari;
    cout << "lanci:\n";
    cin >> lanci;
    srand(time(NULL));
    for (int i = 0; i < lanci; i++) {
        numero = rand()%6;
    }
    if ((numero%2)==pariDispari){
        cout << "hei vinto wow!\n";
    } else {
        cout << "hai perso lol\n";
    }
}

int main() {
    int input;
    cout << "1, 2 o 3\n"; cin >> input;
    switch (input) {
        case 1:
            Es1();
            break;
        case 2:
            Es2();
            break;
        case 3:
            Es3();
            break;
        default:
            cout << "no";
            main();
    }
    return 0;
}
