//
// Created by lucac on 10/11/2023.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    char car;
    int n;
    cout << "inserire la stringa:";
    fflush(stdin);
    getline(cin, a);
    cout << "inserire il carattere da verificare se presente:";
    cin >> car;
    for(int i=0; i<=a.length(); i++)
    {
        if(a[i]==car)
        {
            n++;
            cout << "il carettere è presente\n";
            break;
        }
    }
    if ( (n-1)==0){
        cout << "il carattere non è presente";
    }

    return 0;
}
