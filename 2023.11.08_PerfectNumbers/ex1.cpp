//
// Created by lucac on 11/8/2023.
//
#include <iostream>

using namespace std;

bool isPerfect(int n) {
    int somma = 0;
    for (int i = 1; i < n - 1; i++) {
        if (n % i == 0) {
            somma = somma + i;
        }
    }
    if (n == somma) {
        return true;
    } else {
        return false;
    }
}

void firstNPerfect(int n){
    int count=0;
    for (int i = 1; i < n+8589869056; ++i) {
        if (isPerfect(i)){
            cout << i << " ";
            count++;
        }
        if (count==n){
            return;
        }
    }
}

void findPerfect(int n){
    for (int i = 1; i < n; ++i) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
}



int main() {
    int sel, n, ns[5];
    cout << R"(
------------------------------------------------------------
| N |  Descrizione                                         |
------------------------------------------------------------
| 1 | determinare se un numero è perfetto                  |
| 2 | visualizzare i primi N numeri perfetti;              |
| 3 | trovare tutti i numeri perfetti minori di un valore  |
|   | inserito N;                                          |
| 4 | data una serie di numeri per ognuno stabilire se è   |
|   | perfetto o no.                                       |
| 0 | Esci                                                 |
------------------------------------------------------------
)";
    cout << "Selezione\n -:";
    cin >> sel;
    switch (sel) {
        case 1:
            cout << "Inserire n\n -:";
            cin >> n;
            if (isPerfect(n)){
                cout << n << " è perfetto\n";
            } else {
                cout << n << " non è perfetto\n";
            }
            main();
            break;
        case 2:
            cout << "Inserire n\n -:";
            cin >> n;
            firstNPerfect(n);
            cout << endl;
            main();
            break;
        case 3:
            cout << "Inserire n\n -:";
            cin >> n;
            findPerfect(n);
            cout << endl;
            main();
            break;
        case 4:
            cout << "Inserire n1\n -:"; cin >> ns[0];
            cout << "Inserire n2\n -:"; cin >> ns[1];
            cout << "Inserire n3\n -:"; cin >> ns[2];
            cout << "Inserire n4\n -:"; cin >> ns[3];
            cout << "Inserire n5\n -:"; cin >> ns[4];
            for (int i = 0; i < 5; i++) {
                if (isPerfect(ns[i])){
                    cout << ns[i] << " è perfetto\n";
                }
                else {
                    cout << ns[i] << " non è perfetto\n";
                }
            }
            main();
            break;
        case 0:
            return 0;
        default:
            cout << "nein\n";
            main();
            break;

    }
    return 0;
}
