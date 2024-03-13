#include <iostream>
#include <chrono>

using namespace std;

long long int calcolaSommaFor(int N) {
    long long int sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += i;
    }
    return sum;
}

long long int calcolaSommaFormula(int N) {
    return (N * (N + 1)) / 2;
}

int main() {
    int N = 10000000; 

    auto startFor = chrono::high_resolution_clock::now();
    long long int sumFor = calcolaSommaFor(N);
    auto endFor = chrono::high_resolution_clock::now();
    auto durationFor = chrono::duration_cast<chrono::milliseconds>(endFor - startFor).count();

    auto startFormula = chrono::high_resolution_clock::now();
    long int sumFormula = calcolaSommaFormula(N);
    auto endFormula = chrono::high_resolution_clock::now();
    auto durationFormula = chrono::duration_cast<chrono::milliseconds>(endFormula - startFormula).count();

    cout << "calcolaSommaFor ha impiegato " << durationFor << " millisecondi per calcolare la somma." << endl;
    cout << "calcolaSommaFormula ha impiegato " << durationFormula << " millisecondi per calcolare la somma." << endl;
    
    if (startFor < startFormula) {
        cout << "calcolaSommaFor è più vleoce." << endl;
    } else {
        cout << "calcolaSommaFormula è più vleoce." << endl;
    }
    
    cout << "Complessità Funzione con For: O(n)" << endl;
    cout << "Complessità Funzione con Formula: O(2)" << endl;
    return 0;
}