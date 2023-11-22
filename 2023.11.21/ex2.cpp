//
// Created by lucac on 11/20/2023.
//
#include <iostream>
#include <ctime>

using namespace std;

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
    for (int i = 0; i < size-1; i++) {
        if (a[i]+a[i+1]==10 and a[i]!=10){
            s++;
            i+=1;
        }
    }
    return s;
}

int points(int a[], int size){
    int pt=0, s=0, ss=0;
    for (int i = 0; i < size-1; i+=2) {
        if (a[i]==10){
            pt += 10;
            s=1;
        } else if (a[i]+a[i+1]==10 and a[i]!=10) {
            pt += 10;
            ss=1;
        } else {
            if (s==1){
                pt += (a[i]+a[i+1])*2;
                s=0;
            } else if (ss==1) {
                pt += (a[i]*2)+a[i+1];
                ss=0;
            } else {
                pt += a[i]+a[i+1];
            }
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
    int sel, round;
    cout << "Round (10 nell'esempio)\n -:";
    cin >> round;
    int a[round*2], trows=round*2; //{5,3,4,6,5,2,10,0,4,5,8,0,7,3,2,5,10,0,3,5}
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
            break;
        case 2:
            for (int i = 0; i < trows; i++) {
                cin >> a[i];
                if ((i+1)%2==0){
                    cout << endl;
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
            for (int i = 0; i < trows; i++) {
                cout << a[i] << " ";
            }
            break;
        default:
            cout << "nein\n";
            main();
    }
    outArr(a, trows);
    cout << endl;
    cout << "Strike: " << strike(a, trows) << "\tSpares: " << spare(a, trows) << "\tPunti: " << points(a, trows);
    return 0;
}
