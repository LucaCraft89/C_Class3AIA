//
// Created by lucac on 11/20/2023.
//
#include <iostream>
#include <ctime>

using namespace std;

void outArray(int a[], int s){
    for (int i = 0; i < s; i++) {
        cout << a[i]<< " ";
    }
}

int main() {
    int n, d, m;
    cin >> n; cin >> d;
    srand(time(NULL));
    int cand[n];
    for (int i = 0; i < n+1; i++) {
        if (i+d>n){
            cand[i]=i-d;
        } else {
            cand[i]=i+d;

        }
    }
    outArray(cand, n); cout << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        m=rand()%((n+1)-i);
        cand[m]=0;
        cout << endl;
        for (int j = m; j < n-1; j++) {
            cand[j]=cand[j+1];
        }
        cout << endl;
        if (i==0){
            for (int j = (n-i)-1; j < n; j++) {
                cand[j]=0;
            }
        }
    }
    cout << "Condannato: " << cand[0];
    return 0;
}
