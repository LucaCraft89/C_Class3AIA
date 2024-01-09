//
// Created by lucac on 12/5/2023.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct skier{
    string name;
    int num;
    float time;
};

void floatBubbleSort(float arr[], int n)
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
            }
        }
    }
}

void outAllArr(skier arr[], int n){
    for (int i = 0; i < n; i++) {
        if (arr[i].time==0){
            continue;
        }
        cout << i+1 << ".\t" << arr[i].name << "\t " << arr[i].num << "\t" << arr[i].time << endl;
    }
}

void nullTimes(skier arr[], int n){
    int c=0;
    for (int i = 0; i < n; i++) {
        if (arr[i].time==0){
            cout << arr[i].name << " ha tempo nullo\n";
            c++;
        }
    }
    cout << "totale tempi nulli: " << c << "\n";
}

bool compareByTime(const skier& a, const skier& b) {
    return a.time < b.time;
}

int main() {
    int n, sel;
    cout << "Numero Atleti\n -:";
    cin >> n;
    skier skiers[n];
    for (int i = 0; i < n; i++) {
        cout << "nome atleta " << i+1 << "\n -:";
        fflush(stdin);
        getline(cin, skiers[i].name);
        cout << "cartellino atleta " << i+1 << "\n -:";
        cin >> skiers[i].num;
        cout << "tempo atleta " << i+1 << "\n -:";
        cin >> skiers[i].time;
    }
    sort(skiers, skiers +n , compareByTime);
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
                cout << "L'atleta vincente è:\n" << skiers[0].name << " con cartellino "
                     << skiers[0].num << " con il tempo " << skiers[0].time << endl;
                break;
            case 2:
                cout << "Pos    | Nome  | N |   Tempo \n";
                outAllArr(skiers, n);
                cout << endl;
                break;
            case 3:
                nullTimes(skiers, n);
                break;
            case 9:
                main();
            case 0:
                cout << "quit";
                return 0;
            default:
                cout << "nein\n";
        }
    } while (true);
    return 0;
}
