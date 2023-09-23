//
// Created by lucac on 9/22/2023.
//
#include <iostream>

using namespace std;

int main() {
    string nanoa="Brontolo";
    string nanob="Cucciolo";
    string nanoc="Dotto";
    string nanod="Eolo";
    string nanoe="Gongolo";
    string nanof="Mammolo";
    string nanog="Pisolo";
    string cene="Ceserentola";
    int sel;
    cout << "input a number from 1 to 7:\n -:";
    cin >> sel;
    switch (sel) {
        case 1:
            cout << "You are " << nanoa << "\n";
            break;
        case 2:
            cout << "You are " << nanob << "\n";
            break;
        case 3:
            cout << "You are " << nanoc << "\n";
            break;
        case 4:
            cout << "You are " << nanod << "\n";
            break;
        case 5:
            cout << "You are " << nanoe << "\n";
            break;
        case 6:
            cout << "You are " << nanof << "\n";
            break;
        case 7:
            cout << "You are " << nanog << "\n";
            break;
        default:
            cout << "You are " << cene << "\n";
            break;
    }
    return 0;
}
