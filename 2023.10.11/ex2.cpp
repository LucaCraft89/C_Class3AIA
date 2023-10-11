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
    cout << "inserire il carattere da verificare:";
    cin >> car;
    for(int i=0; i<=a.length(); i++)
    {
        if(a[i]==car)
        {
            n++;
        }
    }
    cout << n-1;

    return 0;
}
