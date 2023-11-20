//
// Created by lucac on 11/15/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a[5]= {2,4,6,1,2}, max=a[0], t;
    for (int i = 0; i < size(a); i++) {
        if (a[i] > max){
            max=a[i];
        }
    }
    cout << max;
    return 0;
}
