//
// Created by lucac on 9/29/2023.
//
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int id, disc;
    double p1, p2, p3, tot, ptot, dtot = 0;
    bool ship;
    cout << "Inserire il proprio id\n -:"; cin >> id;
    cout << "Inserire prezzo item 1\n -:"; cin >> p1;
    cout << "Inserire prezzo item 2\n -:"; cin >> p2;
    cout << "Inserire prezzo item 3\n -:"; cin >> p3;
    ptot = p1+p2+p3;
    if (ptot>=54.76){
        ship = false;
    }
    else {
        ship = true;
        ptot = ptot +7;
    }
    srand(id);
    disc = rand() % 6;
    if (disc==0){
        tot=ptot;
    }
    else {
        dtot=(ptot/100)*disc;
        tot=ptot-dtot;
    }
    if (ship) {
        cout << "Pagherai 7 euro di pedizione.\n";
    }
    else {
        cout << "Hai ottenuto la spedione gratuita!!!!!\n";
    }
    cout << "Prezzi:\n   Articolo 1: " << p1 << "\n   Articolo 2: " << p2 << "\n   Articolo 3: " << p3 << "\nTotale: "<< ptot << "\nSconto Ottenuto: " << disc << "\nSconto Sul Totale: " << dtot << "\nSoldi da sganciare: " << "Drumroll........." << " \n--------------------\n\t" << tot << " \n--------------------\n";
    return 0;
}
