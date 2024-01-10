//
// Created by lucac on 10/17/2023.
//
#include <iostream>

using namespace std;

int main() {
    int sel;
    do {
        cout << R"(
    1. calcolate la moltiplicazione dei primi n numeri (fattoriale)
    2. somma di numeri positivi (uscita dalla richiesta se non positivi)
    3. determinare se il numero passato è primo o meno.
    0. stacca che ci stanno tracciando
        )"; cout << "\n -:";
        cin >> sel;
        switch (sel) {
            case 1:
                int inp, result;
                cout << "inserire er numerooo\n -:";
                cin >> inp;
                for (int i = 0; i < inp; ++i) {
                    result = result * i+1;
                }
                cout << result <<endl;
                break;
            case 2:
                int a, b;
                cout << "inserire er primer nombre\n -:"; cin >> a;
                cout << "inserire er secundo nombre\n -:"; cin >> b;
                if (a<0 or b<0){
                    cout << "ATTENZIONE TI SI MONA tio ho detto positivi!!!!!!!!!!!!!!\n";
                    break;
                }
                cout << a+b << endl;
                break;
            case 3:
                int c;
                bool isPrime;
                cout << "e metticelo sto numero\n -:"; cin >> c;
                for (int i = 2; i < c; ++i) {
                    if (c%i){
                        isPrime = true;
                    }
                    else {
                        isPrime = false;
                        cout << "il numero non è primo\n";
                        break;
                    }
                }
                if (isPrime or c==1 or c==2){
                    cout << "il numero è primo|||\n";
                }
                break;
            case 0:
                return 1;
                break;

        }
    } while (1==1);
    return 0;
}
