#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const long long int SIZE = 10000;

long long int trovaMassimoFor(const long long int* array, int size) {
    long long int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

long long int trovaMassimoBubbleSort(long long int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    return array[size - 1];
}

int main() {
    
    long long int array[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000 + 1;
    }

    clock_t startFor = clock();
    long long int maxFor = trovaMassimoFor(array, SIZE);
    clock_t endFor = clock();
    double timeFor = double(endFor - startFor) / CLOCKS_PER_SEC;

    clock_t startBubbleSort = clock();
    long long int maxBubbleSort = trovaMassimoBubbleSort(array, SIZE);
    clock_t endBubbleSort = clock();
    double timeBubbleSort = double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    cout << "Valore massimo trovato con ciclo for: " << maxFor << endl;
    cout << "Tempo impiegato con ciclo for: " << timeFor << " secondi" << endl;
    cout << "Valore massimo trovato con bubble sort: " << maxBubbleSort << endl;
    cout << "Tempo impiegato con bubble sort: " << timeBubbleSort << " secondi" << endl;
    cout << "Complessità Funzione con For: O(n)" << endl;
    cout << "Complessità Funzione con BubbleSort: O(n^2)" << endl;
    return 0;
}