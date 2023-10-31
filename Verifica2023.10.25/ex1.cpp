//
// Created by lucac on 10/25/2023.
//

// Luca Dall'Acqua

#include <iostream>
#include <ctime>

using namespace std;

// Funzione per restituire 0 per uscire o 9 per rimanere nel programma con 50% di probabilità
int randExit(){
    srand(time(NULL));
    if (rand()%2) {
        cout << "Fortunato\nAdios\n";
        return 0;
    } else {
        cout << "Hai perso Riprova\n";
        return 9;
    }
}

//Funzione che converte un numero decimale fornito dall'utente in binario a 20 bit
void dec2Bin(int input){
    int j=0, jj=0, temp=0;
    int bin[20];
    for (int i = 0; i < 20; ++i) {
        if (input%2){
            bin[i]=1;
            input=input/2;
        }
        else {
            bin[i]=0;
            input=input/2;
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
}

// Funzione per evocare un demone
void spawn_entityDeamonRabbit(){
    while (true) {
        cout << "(\\(\\\n( -.-)\no_(" << '"' << ")(" << '"' << ")\n\n";
    }
}

// Funzione per stampre a schermo una bandiera bianca
void bandieraBiancha(){
    cout << "Tregua, ti prego pensa!!\n\n";
    cout << R"(
@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@
||
||
||
||
||
)";
    cout << "Bandiera Bianca di rassegnazione\n";
}


// Funzione per stampare a schermo il menu
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
| 6 | Decimale a Binario                                   |
| 0 | Forse esci                                           |
------------------------------------------------------------
)";
}

int main() {
    int sel=9,j=0, k=0, l=0, input=0, accumulatoro=0, failCounter=0;
    do {
        menu();
        cout << "Selezione-: ";
        cin >> sel;
        switch (sel) {
            case 1:
                // Esercizio 1: Stampa a video i numeri pari che vanno da 100 a -66
                cout << endl;
                for (int i = 100; i > -66-2; i-=2) {
                    cout << i << endl;
                }
                break;
            case 2:
                //Esercizio 2: Stampo 3 riche di asterischi da 30 asterischi l'uno in 3 modi diversi
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
                //Esercizio 3: evoco il demone coniglio
                cout << endl;
                spawn_entityDeamonRabbit();
                break;
            case 4:
                //Esercizio 4: Esercizio troll: continuo a chiedere numeri positivi e sommarli senza far vedere
                // la somma all'utente, me se viene inserito un numero negativo faccio vedere la media dei numeri
                //inseriti meno quello negtivo
                while (input>=0){
                    l++;
                    accumulatoro = accumulatoro + input;
                    cout << "Inserire numero positivo\n -:";
                    cin >> input;
                }
                cout << accumulatoro/(l-1);
                l=0; input=0; accumulatoro=0;
                break;
            case 5:
                //Esercio 5: Quadreto numero con controllo sull'input che dve essere compreso fra 1 e 10
                cout << "Inserire un numero fra 1 e 10\n -:";
                cin >> input;
                while (input< 1 or input >10){
                    cout << "allora vedi che non hai capito\nInserire un numero COMPRESO FRA 1 E 10\n -:";
                    cin >> input;
                }
                for (int i = 0; i < input; i++) {
                    for (int m = (input)*(input-i); m > ((input)*(input-i))-input ; m--) {
                        cout << m << " ";
                    }
                    cout << endl;
                }
                break;
            case 6:
                //Esercizio 6: a piacimento: conversione da decimale a binario
                cout << "Inserire un numero decimale\n -:";
                cin >> input;
                dec2Bin(input);
                break;
            case 0:
                //Esercizio 7: uscita cokn 50% di probabilità
                sel = randExit();
                break;
            default:
                //avviso l'utente se sbaglia troppe volte la sele<ione ed ad una certa mi rassegno
                cout << "Allora vedi che non capisci nulla\n";
                failCounter++;
                if (failCounter > 10){
                    bandieraBiancha();
                    sel=0;
                } else if (failCounter > 3){
                    cout << "Non molli mai e?\n";
                }
        }
    } while (sel!=0);
    return 0;
}
