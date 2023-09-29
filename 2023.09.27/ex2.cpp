//
// Created by lucac on 9/27/2023.
//
#include <iostream>

using namespace std;

float somma() {
    float a, b;
    cout << "inserire a\n -:"; cin >> a;
    cout << "inserire b\n -:"; cin >> b;
    return a+b;
}

bool intervallo() {
    float a, b, val;
    cout << "inserire primo punto intervallo\n -:"; cin >> a;
    cout << "inserire secondo punto intervallo\n -:"; cin >> b;
    cout << "inserire a\n -:"; cin >> val;
    if (a>b){
        cout << "Input non valido (il primo punto deve essere più piccolo del del secondo)\n";
        intervallo();
    }
    else {
        if (val>a and val<b){
            return 1;
        }
        else {
            return 0;
        }
    }
}

void barzelletta(){
    cout << "oct(31) = dec(25)";
}

int main() {
    int sel;
    cout << "1) somma due numeri\n2) determinare se un punto è interno ad un intervallo\n3) Leggi una barzelletta\n -:"; cin >> sel;
    switch (sel) {
        case 1:
            cout << somma() << " è la somma";
            break;
        case 2:
            if (intervallo()){
                cout << "il valore è contenuto nell'intevallo";
            }
            else {
                cout << "il valore NON è contenuto nell'intervallo";
            }
            break;
        case 3:
            barzelletta();
            break;
        default:
            cout << "input errato \n";
            main();
    }
    return 0;
}
