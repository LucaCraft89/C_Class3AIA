#include <iostream>

// Funzione per scambiare due elementi dell'array
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione per trovare il punto di divisione dell'array
int partition(char arr[], int low, int high) {
    char pivot = arr[high]; // scegliamo l'ultimo elemento come pivot
    int i = (low - 1); // indice del più piccolo elemento

    for (int j = low; j <= high - 1; j++) {
        // Se l'elemento corrente è più piccolo o uguale al pivot
        if (arr[j] <= pivot) {
            i++; // incrementa l'indice del più piccolo elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Funzione ricorsiva per eseguire il QuickSort
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        // Trova il punto di divisione dell'array
        int pi = partition(arr, low, high);

        // Ordina ricorsivamente gli elementi prima e dopo il punto di divisione
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char arr[] = {'z', 'a', 'b', 'c', 'f', 'e', 'd'};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array non ordinato: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    std::cout << "\nArray ordinato: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }


    return 0;
}
