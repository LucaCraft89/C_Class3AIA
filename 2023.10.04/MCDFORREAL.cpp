//
// Created by lucac on 10/4/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b, i=1;
    cin >> a; cin >> b;
    while (a < 0 or b < 0){
        cin >> a; cin >> b;
    }
    do {
        i=i+1;
    } while (a%i or b%i);
    cout << i;
    return 0;
}
