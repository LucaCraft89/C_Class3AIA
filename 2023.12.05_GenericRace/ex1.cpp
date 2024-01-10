//
// Created by lucac on 12/5/2023.
//
#include <iostream>
#include <string>

using namespace std;

void floatBubbleSort(float arr[], int n, string arr2[], int arr3[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                string temps = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temps;
                int tempr = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = tempr;
            }
        }
    }
}

void outAllArr(string arr[], int arr2[], float arr3[], int n){
    for (int i = 0; i < n; i++) {
        if (arr3[i]==0){
            continue;
        }
        cout << i+1 << ".\t" << arr[i] << "\t " << arr2[i] << "\t" << arr3[i] << endl;
    }
}

int nullTimes(float arr[], int n){
    int c=0;
    for (int i = 0; i < n; i++) {
        if (arr[i]==0){
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    cout << "Numero Atleti\n -:";
    cin >> n;
    string nomi[n];
    int numer[n], sel;
    float tempi[n];
    for (int i = 0; i < n; i++) {
        cout << "nome atleta " << i+1 << "\n -:";
        fflush(stdin);
        getline(cin, nomi[i]);
        cout << "cartellino atleta " << i+1 << "\n -:";
        cin >> numer[i];
        cout << "tempo atleta " << i+1 << "\n -:";
        cin >> tempi[i];
    }
    floatBubbleSort(tempi, n, nomi, numer);
    do {
        cout << R"(
1. - visualizzare il vincitore;
2. - visualizzare la classifica (elenco ordinato con ogni n. pettorale - tempo);
3. - comunicare  il numero degli atleti ritirati (tempo=0);
9. - riesegui
0. - quit
    )";
        cout << "\nSelezione\n -:";
        cin >> sel;
        switch (sel) {
            case 1:
                cout << "L'atleta vincente è:\n" << nomi[0] << " con cartellino "
                << numer[0] << " con il tempo " << tempi[0] << endl;
                break;
            case 2:
                cout << "Pos    | Nome  | N |   Tempo \n";
                outAllArr(nomi, numer, tempi, n);
                cout << endl;
                break;
            case 3:
                cout << "tempi nulli: " << nullTimes(tempi, n) << endl;
                break;
            case 9:
                main();
            case 0:
                return 0;
            default:
                cout << "nein\n";
        }
    } while (true);
    return 0;
}
