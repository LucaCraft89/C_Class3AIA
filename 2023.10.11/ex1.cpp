//
// Created by lucac on 10/11/2023.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int menu(string a, string b) {
    int sel; int ss;
    cout << R"(
Selezionare cosa si vuole fare:
    1. visualizzare la lunghezza di ciascuna stringa
    2. verificare se le stringhe sono uguali
    3. visualizzare la pių piccola in ordine alfabetico
    4. visualizzare la pių corta
    5. concatenare le due stringhe e mettere il risultato in una terza stringa
    6. reinserire le stringhe
    7. ripetere l'esecuzione dell'intero programma
    8. Convertire una stringa in maiuscolo
    9. Convertire una stringha tutta in minuscolo
    0. uscire
)";
    cout << " -:"; cin >> sel;
    switch (sel) {
        case 1:
            cout << "La pirma string aè lungha: " << a.size() << endl;
            cout << "La seconda string aè lungha: " << b.size() << endl;
            menu(a, b);
            break;
        case 2:
            if (a == b){
                cout << "entrambe le stringhe sono uguali\n";

            } else {
                cout << "entrambe le stringhe non sono uguali\n";
            }
            menu(a, b);
            break;
        case 3:
            if (a>b){
                cout << a;
            } else {
                cout << b;
            }
            menu(a, b);
            break;
        case 4:
            if (a.length() > b.length()){
                cout << "La stringha più corta è: " << b << endl;
            }
            else if (a.length() < b.length()){
                cout << "La stringha più corta è: " << a<<endl;
            } else {
                cout << "le stringhe sono uguali\n";
            }
            menu(a, b);
            break;
        case 5:
            cout << "risultato: " << a+b << endl;
            menu(a, b);
            break;
        case 6:
            a=' '; b=' ';
            cout << "Inserire la prima stringha\n -:";
            fflush(stdin);
            getline(cin, a);
            if (0);
            cout << "Inserire la seconda stringha\n -:";
            fflush(stdin);
            getline(cin, b);
            menu(a, b);
            break;
        case 7:
            return 1;
        case 8:
            cout << "Inserire quale stringha si vuole convertire\n   1.a\t2.b\n";
            cin >> ss;
            if (ss==1){
                transform(a.begin(), a.end(),a.begin(), ::toupper);
                cout << "riusltato: " << a << endl;
            } else if (ss==2){
                transform(b.begin(), b.end(),b.begin(), ::toupper);
                cout << "riusltato: " << b << endl;
            }
            else {
                cout << "selezione non valida\n";
            }
            menu(a,b);
            break;
        case 9:
            cout << "Inserire quale stringha si vuole convertire\n   1. a\t2.b\n";
            cin >> ss;
            if (ss==1){
                transform(a.begin(), a.end(),a.begin(), ::tolower);
                cout << "riusltato: " << a << endl;
            } else if (ss==2){
                transform(b.begin(), b.end(),b.begin(), ::tolower);
                cout << "riusltato: " << b << endl;
            }
            else {
                cout << "selezione non valida\n";
            }
            menu(a,b);
            break;
        case 0:
            return 0;
        default:
            cout << "Selezione non vaida\n";
            menu(a, b);
    }
    return 0;
}

int main() {
    string a, b;
    cout << "buonasera pancla\n";
    cout << "Inserire la prima stringha\n -:";
    fflush(stdin);
    getline(cin, a);
    cout << "Inserire la seconda stringha\n -:";
    fflush(stdin);
    getline(cin, b);
    if (menu(a,b) ==1 ){
        main();
    }
    else {
        return 0;
    }
}
