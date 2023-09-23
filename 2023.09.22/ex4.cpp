//
// Created by lucac on 9/22/2023.
//
#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, max, min;
    cout << "input a:\n -:";
    cin >> a;
    cout << "input b:\n -:";
    cin >> b;
    cout << "input c:\n -:";
    cin >> c;
    cout << "input d:\n -:";
    cin >> d;
    if (a>b and a>c and a>d) {
        max=a;
    }
    else if (b>a and b>c and b>d) {
        max=b;
    }
    else if (c>b and c>a and c>d) {
        max=c;
    }
    else {
        max=d;
    }
    if (a<b and a<c and a<d) {
        min=a;
    }
    else if (b<a and b<c and b<d) {
        min=b;
    }
    else if (c<b and c<a and c<d) {
        min=c;
    }
    else {
        min=d;
    }
    cout << "Biggest number: " << max << "   Smallest number: " << min << "\n";

    return 0;
}
