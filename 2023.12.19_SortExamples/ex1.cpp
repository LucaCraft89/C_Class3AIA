//
// Created by lucac on 12/16/2023.
//
#include <iostream>
#include <ctime>
#include <chrono>

const int MAX = 100000;

using namespace std;

void optimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n-1; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then the array is sorted.
        if(!swapped)
            break;
    }
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

long long getCurrentTimeInMilliseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main() {
    int arr[MAX], arr2[MAX], arr3[MAX], arr4[MAX];
    long bf,af;
    srand(time(NULL));
    bf = getCurrentTimeInMilliseconds();
    for (int i = 0; i < MAX; i++)
    {
        arr[i]=rand()%20;
    }  
    af = getCurrentTimeInMilliseconds();
    cout << "Fill: " << af-bf << endl;
    bf = getCurrentTimeInMilliseconds();
    for (int i = 0; i < MAX; i++)
    {
        arr2[i]=arr[i];
    }   
    for (int i = 0; i < MAX; i++)
    {
        arr3[i]=arr[i];
    }  
    for (int i = 0; i < MAX; i++)
    {
        arr4[i]=arr[i];
    }        
    af = getCurrentTimeInMilliseconds();
    cout << "Copy: " << af-bf << endl;
    bf = getCurrentTimeInMilliseconds();
    bubbleSort(arr, MAX);
    af = getCurrentTimeInMilliseconds();-
    cout << "Bsort: " << af-bf << endl;
    bf = getCurrentTimeInMilliseconds();
    optimizedBubbleSort(arr4, MAX);
    af = getCurrentTimeInMilliseconds();
    cout << "OBsort: " << af-bf << endl;
    bf = getCurrentTimeInMilliseconds();
    quickSort(arr2, 0, MAX-1);
    af = getCurrentTimeInMilliseconds();
    cout << "Qsort: " << af-bf << endl;
    bf = getCurrentTimeInMilliseconds();
    shellSort(arr3, MAX);
    af = getCurrentTimeInMilliseconds();
    cout << "Buggato Ssort: " << af-bf << endl;
    int numero, fn;
    cin >> numero;
    bf = getCurrentTimeInMilliseconds();
    fn = binarySearch(arr, MAX, numero);
    af = getCurrentTimeInMilliseconds();
    cout << "Bsearch: " << af-bf << "\nIndex: " << fn << endl;
    cout << "Ciao Luca\n";
    cout << "Ciao Boschian\n";
    return 0;
}
