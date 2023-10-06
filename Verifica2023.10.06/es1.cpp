//
// Created by lucac on 10/6/2023.
//
#include <iostream>

//Importo la libreria necessaria per la funzione sqrt()
#include <cmath>

using namespace std;

int main() {
    // Definisco le Variabili: a=coeff x^2, b=coeff x, c=TermineNoto
    float a, b, c, delta, x1, x2 = 0;

    //Stampo a schermo il titolo del programma
    cout << "-----------------------------------------------\n";
    cout << "   Calcolatore di equazioni di secondo grado   \n";
    cout << "-----------------------------------------------\n";
    cout << endl;

    //Chiedo in input i coefficienti e il termine noto
    cout << "Inserire il coefficiente di x^2\n -:";
    cin >> a;
    cout << "Inserire il coefficiente di x\n -:";
    cin >> b;
    cout << "Inserire il termine noto\n -:";
    cin >> c;

    //Stampo a schermo l'equazione dopo l'inkserimento
    cout << "Equazione inserita:\n   " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    //Controllo se tutti i coefficienti sono nulli e di conseguenza avviso l'utente
    if (a==0 and b==0 and c==0) {
        cout << "l'equazione risulta indeterminata!!\n";
    }

    //Controllo se il coefficiente di x^2 è negativo e di conseguenza inverto i segni dell'equazione
    else if (a<0){
        //avviso l'utente
        cout << "il coefficiente di x^2 risulta negativo inverto i segni\n: ";

        //Inverto i Segno
        a=-(a);
        b=-(b);
        c=-(c);

        //Stampo a scherma la situazione attuale
        cout << "Equazione attuale:\n   " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }

    //Controllo se a è uguale a 0 e di conseguenza calcolo come se fosse di primo grado
    else if (a==0){
        //Avviso l'utente
        cout << "L'equazione inserita è di primo grado (coefficiente di x^2 = 0)\n";

        //Procedo con la risoluzione
        c=-(c);
        cout << "Equazione attuale:\n   " << b << "x = " << c << endl;
        x1=c/b;

        //Stampo a Schermo le soluzioni
        cout << "La soluzione equivale a x = " << x1 << endl;
    }

    // Se Entrabi i coefficienti di x^2 e x sono diversi da 0 procedo con la risoluzione
    else if (b!=0 and a!=0){
        //Calcolo il determinante
        delta = (float)(pow(b,2))- (4*(a*c));

        //Controllo de il determinante è uguale a 0
        if (delta==0){
            //Avviso l'utente del fatto che le soluzioni sono uguali
            cout << "Le soluzioni sono coincidenti\n";

            //Calcolo le soluzioni
            x1= (-(b) + sqrt(delta))/(2*a);
            x2=x1;
        }

        //Controllo se il determinante è negativo è avverto l'utente che l'equazione è impossibile
        else if (delta<0){
            cout << "l'equazione risulta impossibile!!\n";
        }

        //Altrimenti Procedo normalmenta calcolando le soluzioni
        else {
            x1=(-(b) + sqrt(delta))/(2*a);
            x2=(-(b) - sqrt(delta))/(2*a);
        }

        //Stampo a schermo le soluzioni finali
        cout << "Le soluzioni sono: \n   x1: " << x1 << "\n   x2: " << x2 << endl;
    }
    return 0;
}
