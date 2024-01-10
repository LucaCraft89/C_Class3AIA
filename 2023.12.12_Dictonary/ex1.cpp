//
// Created by lucac on 12/12/2023.
//

// ATTENZIONE: Per l'utilizzo di lettura e scrittura su file si prega di creare un file "dict.txt"
// Nella setta directory del build
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXw=200;

const string path = "dict.txt";

struct word{
    string lang1;
    string lang2;
};

void BubbleSort(int n, string arr2[], string arr1[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr2[j] > arr2[j+1])
            {
                string temps = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temps;
                string temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
                if (arr2[i+1]=="z-1"){
                    return;
                }
            }
        }
    }
}

void sortedOut(int n, string arr2[], string arr1[]){
    for (int i = 0; i < n; i++) {
        if (arr2[i]=="z-2"){
            cout << arr2[i] << " | " << arr1[i] << endl;

        } else {
            cout << arr2[i] << " | " << arr1[i] << endl;
        }
        if (arr2[i+1]=="z-1"){
            return;
        }
    }
}

int binFind(string v[], int d, string n){
    int s=0, sx=0, dx=d-1, md;
    do{
        md=(sx+dx)/2;
        if (v[sx]==n || v[dx]==n || v[md]==n) {
            s=1;
        }
        else{
            dx= md-1;
        }
    } while (sx<=dx && s==0);
    return s;
}

int main(){
    word words[MAXw];
    string temp[MAXw], temp2[MAXw], str, tword, line, lines[MAXw];
    int out, l=0, sel, se, sel2, posi, k=0, loc;
    ifstream myFile(path);
    ofstream outFile(path);
    for (int i = 0; i < MAXw; i++) {
        words[i].lang1 = "z-1";
        words[i].lang2 = "z-1";
    }
    do {
    cout << R"(
1. Memorizzare un insieme di vocaboli con la relativa traduzione in un'altra lingua.
2. Visualizzare il dizionario ordinato in ordine alfabetico, secondo una lingua a
   scelta.
3. Modificare e Cancellare una parola nel dizionario, secondo una lingua a scelta
   (utilizzare la funzione di Ricerca).
4. Salvare il dizionario in un file di testo.
5. Recuperare il dizionario da un file di testo.
0. Uscire
)";
        cout << "Selezione\n -:";
        cin >> sel;
        switch (sel) {
            case 1:
                do {
                    cout << "Inserire parole in lingua 1\n -:";
                    fflush(stdin);
                    getline(cin, words[l].lang1);
                    cout << "Inserire parole in lingua 2\n -:";
                    fflush(stdin);
                    getline(cin, words[l].lang2);
                    do {
                        cout << "Iserimento finito? (1=si, 0=no)\n -:"; cin >> out;
                    } while (out != 1 and out != 0);
                    l++;
                } while (out!=1 and l<200);
                break;
            case 2:
                cout << "Lingua 1 o Lingua 2?\n -:"; cin >> se;
                if (se==1){
                    for (int i = 0; i < MAXw; i++) {
                        temp[i] = words[i].lang1;
                        temp2[i] = words[i].lang2;
                    }
                } else if (se==2){
                    for (int i = 0; i < MAXw; i++) {
                        temp[i] = words[i].lang2;
                        temp2[i] = words[i].lang1;
                    }
                } else {
                    cout << "no";
                    break;
                }
                BubbleSort(MAXw, temp, temp2);
                sortedOut(MAXw, temp, temp2);
                break;
            case 3:
                cout << "Lingua 1 o Lingua 2?\n -:"; cin >> se;
                if (se==1){
                    for (int i = 0; i < MAXw; i++) {
                        temp[i] = words[i].lang1;
                        temp2[i] = words[i].lang2;
                    }
                } else if (se==2){
                    for (int i = 0; i < MAXw; i++) {
                        temp[i] = words[i].lang2;
                        temp2[i] = words[i].lang1;
                    }
                } else {
                    cout << "no";
                }
                BubbleSort(MAXw, temp, temp2);
                cout << "Parola da Cercare?\n -:";
                fflush(stdin);
                getline(cin, str);
                posi = binFind(temp, MAXw, str)+0;
                if (posi==-1){
                    cout << "Parola non trovata!!\n";
                    break;
                } else {
                    cout << "Parola trovo all'indice " << posi << endl;
                }
                cout << "Cosa si vuole fare?(1=modificare, 2=eliminare)\n -:";
                cin >> sel2;
                switch (sel2) {
                    case 1:
                        cout << "inserire parola nuova in lingua 1\n -:";
                        fflush(stdin);
                        getline(cin, tword);
                        words[posi-1].lang1=tword;
                        tword="";
                        cout << "inserire parola nuova in lingua 2\n -:";
                        fflush(stdin);
                        getline(cin, tword);
                        words[posi-1].lang2=tword;
                        tword="";
                        break;
                    case 2:
                        for (int i = posi; i < MAXw-1; i++) {
                            words[i].lang1 = words[i+1].lang1;
                            words[i].lang2 = words[i+1].lang2;
                        }
                        break;
                }
                break;
            case 4:
                if (!outFile.is_open()) {
                    cout << "Non riesco ad prire il file!!" << endl;
                    break;
                }
                for (int i = 0; i < MAXw; i++) {
                    outFile << words[i].lang1 << "_" << words[i].lang2 << "\n";
                    if (words[i+1].lang1=="z-1"){
                        break;
                    }
                }
                cout << "Salvato con successo!\n";
                break;
            case 5:
                if (myFile.is_open())
                {
                    while (getline(myFile,line)){
                        lines[k]=line;
                        k++;
                    }
                }
                else {
                    cout << "file non accessibile\n";
                    break;
                }
                for (int i = 0; i < MAXw; i++) {
                    loc = lines[i].find('_');
                    if (loc != string::npos) {
                        words[i].lang1 = lines[i].substr(0, loc);
                        words[i].lang2 = lines[i].substr(loc + 1);
                    } else {
                        break;
                    }
                }
                cout << "Letto con successo!\n";
                break;
            case 0:
                return 0;
            default:
                cout << "nein";
        }
    } while (sel!=0);
    return 0;
}
