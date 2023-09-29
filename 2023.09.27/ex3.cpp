//
// Created by lucac on 9/27/2023.
//
#include <iostream>

using namespace std;

int main() {
    int p_a, p_b;
    cout << "1) sasso\t2) carta\t3) forbice\n Player 1-:"; cin >> p_a;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "1) sasso\t2) carta\t3) forbice\n Player 2-:"; cin >> p_b;
    if (p_a>3 or p_b>3 or p_a<1 or p_b<1){
        cout << "input non valido";
        main();
    }
    if (p_a=p_b){
        cout << "pareggio";
    }
    else if (p_a=1 and p_b=2) {
        cout << "player 2 vince\n";
    }
    else if (p_a=1 and p_b=3) {
        cout << "player 1 vince\n";
    }
    else if (p_a=2 and p_b=1) {
        cout << "player 1 vince\n";
    }
    else if (p_a=2 and p_b=3) {
        cout << "player 2 vince\n";
    }
    else if (p_a=3 and p_b=1) {
        cout << "player 2 vince\n";
    }
    else if (p_a=3 and p_b=2) {
        cout << "player 1 vince\n";
    }


    return 0;
}
