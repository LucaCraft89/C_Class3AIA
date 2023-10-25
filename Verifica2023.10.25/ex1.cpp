//
// Created by lucac on 10/25/2023.
//

// Luca Dall'Acqua

#include <iostream>

using namespace std;

void menu() {
    cout << R"(
------------------------------------------------------------
| N |  Descrizione                                         |
------------------------------------------------------------
| 1 | Stampa a video i numeri pari che vanno da 100 a -66  |
| 2 | Divertiamoci con 3 righe di asterischi!              |
| 3 | Evochiamo un demone                                  |
| 4 | Mediamo....                                          |
| 5 | Disegniamo un quadrato numerato!                     |
| 6 | Fantasia dello chef                                  |
| 0 | Forse esci                                           |
------------------------------------------------------------
)";
}

int main() {
    int sel=9,j=0, k=0;;
    do {
        menu();
        cout << "Selezione-: ";
        cin >> sel;
        switch (sel) {
            case 1:
                cout << endl;
                for (int i = 100; i > -66-2; i-=2) {
                    cout << i << endl;
                }
                break;
            case 2:
                cout << endl;
                for (int i = 0; i < 30; ++i) {
                    cout << "*";
                }
                cout <<endl;
                while (j<30){
                    j++;
                    cout << "*";
                }
                cout << endl;
                do {
                    k++;
                    cout << "*";
                } while (k<30);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 0:
                cout << "Adios\n";
                break;
        }
    } while (sel!=0);
    return 0;
}
