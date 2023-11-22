//
// Created by lucac on 11/20/2023.
//
#include <iostream>
#include <ctime>

using namespace std;

bool isValid(int n){
    return (n<0 or n>10);
}

int strike(int a[], int size){
    int s=0;
    for (int i = 0; i < size; i++) {
        if (a[i]==10){
            s++;
        }
    }
    return s;
}

int spare(int a[], int size){
    int s=0;
    for (int i = 0; i < size-1; i+=2) {
        if (a[i]+a[i+1]==10 and a[i]!=10){
            s++;
        }
    }
    return s;
}

int points(int a[], int size){
    int pt=0;
    for (int i = 0; i < size-1; i+=2) {
        if (a[i]==10){
            pt += 10;
            pt += (a[i]+a[i+1])*2;
        } else if (a[i]+a[i+1]==10 and a[i]!=10) {
            pt += 10;
            pt += (a[i]*2)+a[i+1];
        } else {
            pt += a[i]+a[i+1];
        }
    }
    return pt;
}

void outArr(int a[], int size){
    cout << "| ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
        if ((i-1)%2==0){
            cout << "| ";
        }
    }
}



int main() {
    srand(time(NULL));
    int sel, round, p2;
    cout << "2 giocatori (1=si, 0=no)?\n -:";
    cin >> p2;
    cout << "Round (10 nell'esempio)\n -:";
    cin >> round;
    int a[round*2], trows=round*2; //{5,3,4,6,5,2,10,0,4,5,8,0,7,3,2,5,10,0,3,5}
    int b[round*2];
    for (int i = 0; i < trows; i++) {
        a[i]=-1;
        b[i]=-1;
    }
    cout << R"(
Come si desidera inserire l'array:
    1. Esempio ({5,3,4,6,5,2,10,0,4,5,8,0,7,3,2,5,10,0,3,5})
    2. Manualmente
    3. Random
)";
    cout << "\n -:";
    cin >> sel;
    switch (sel) {
        case 1:
            a[0]=5; a[1]=3; a[2]=4; a[3]=6; a[4]=5; a[5]=2; a[6]=10; a[7]=0; a[8]=4; a[9]=5; a[10]=8; a[11]=0; a[12]=7; a[13]=3; a[14]=2; a[15]=5; a[16]=10; a[17]=0; a[18]=3; a[19]=5;
            if (p2==1){
                b[0]=5; b[1]=3; b[2]=4; b[3]=6; b[4]=5; b[5]=2; b[6]=10; b[7]=0; b[8]=4; b[9]=5; b[10]=8; b[11]=0; b[12]=7; b[13]=3; b[14]=2; b[15]=5; b[16]=10; b[17]=0; b[18]=3; b[19]=5;
            }
            break;
        case 2:
            for (int i = 0; i < trows; i++) {
                cout << "-:";
                cin >> a[i];
                while (!isValid(a[i])){
                    cout << "è no on va bene\n";
                    cout << "-:";
                    cin >> a[i];
                }
                if ((i+1)%2==0){
                    cout << endl;
                }
                if (a[i]==10){
                    a[i+1]=0;
                    i++;
                }
            }
            if (p2==1) {
                cout << "\nora p2";
                for (int i = 0; i < trows; i++) {
                    cin >> b[i];
                    if ((i + 1) % 2 == 0) {
                        cout << endl;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < trows; i++) {
                a[i]=rand()%11;
                if (a[i]==10){
                    a[i+1]=0;
                    i++;
                } else if (a[i-1]+a[i]>10 and a[i-1]!=0){
                    while (a[i-1]+a[i]>10 and a[i-1]!=0){
                        a[i]=rand()%11;
                    }
                }
            }
            if (p2==1) {
                for (int i = 0; i < trows; i++) {
                    b[i] = rand() % 11;
                    if (b[i] == 10) {
                        b[i + 1] = 0;
                        i++;
                    } else if (b[i - 1] + b[i] > 10 and b[i - 1] != 0) {
                        while (b[i - 1] + b[i] > 10 and b[i - 1] != 0) {
                            b[i] = rand() % 11;
                        }
                    }
                }
            }
            break;
        default:
            cout << "nein\n";
            main();
    }
    cout <<  "P1: ";
    outArr(a, trows);
    if (p2==1){
        cout << endl;
        cout <<  "P2: ";
        outArr(b, trows);
    }
    cout << endl;
    cout << "P1: " << "Strike: " << strike(a, trows) << "\tSpares: " << spare(a, trows) << "\tPunti: " << points(a, trows);
    if (p2==1) {
        cout << endl;
        cout <<  "P2: " << "Strike: " << strike(b, trows) << "\tSpares: " << spare(b, trows) << "\tPunti: " << points(b, trows);
        if (points(a, trows)> points(b, trows)){
            cout << "\n\n VINCE P1 \n\n";
        } else if (points(a, trows)==points(b, trows)) {
            cout << "\n\n PAREGGIO \n\n";
        } else {
            cout << "\n\n VINCE P2 \n\n";
        }
    }
    return 0;
}
