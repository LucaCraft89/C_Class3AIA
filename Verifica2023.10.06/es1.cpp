//
// Created by lucac on 10/6/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c, delta, x1, x2 = 0;
    cout << "-----------------------------------------------\n";
    cout << "   Calcolatore di equazioni di secondo grado   \n";
    cout << "-----------------------------------------------\n";
    cout << endl;
    cout << "Inserire il coefficiente di x^2\n -:";
    cin >> a;
    cout << "Inserire il coefficiente di x\n -:";
    cin >> b;
    cout << "Inserire il termine noto\n -:";
    cin >> c;
    cout << "Equazione inserita:\n   " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    if (a<0){
        cout << "il coefficiente di x^2 risulta negativo inverto i segni\n: ";
        a=-(a);
        b=-(b);
        c=-(c);
        cout << "Equazione attuale:\n   " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
    else if (a==0){
        cout << "L'equazione inserita è di primo grado (coefficiente di x^2 = 0)\n";
        c=-(c);
        cout << "Equazione attuale:\n   " << b << "x = " << c << endl;
        x1=c/b;
        cout << "La soluzione equivale a x = " << x1 << endl;
    }
    if (b==0) {
        cout << "l'equazione risulta indeterminata!!\n";
    }
    else if (b!=0 and a!=0){
        delta = (float)(pow(b,2))- (4*(a*c));
        if (delta==0){
            cout << "Le soluzioni sono coincidenti\n";
            x1= (-(b) + sqrt(delta))/(2*a);
            x2=x1;
        }
        else if (delta<0){
            cout << "l'equazione risulta impossibile!!\n";
        }
        else {
            x1=(-(b) + sqrt(delta))/(2*a);
            x2=(-(b) - sqrt(delta))/(2*a);
        }
        cout << "Le soluzioni sono: \n   x1: " << x1 << "\n   x2: " << x2 << endl;
    }
    return 0;
}
