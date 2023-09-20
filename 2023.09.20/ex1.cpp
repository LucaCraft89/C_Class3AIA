//
// Created by lucac on 9/20/2023.
//
#include <iostream>

using namespace std;

int main() {
    int hour, min, sec;
    cout << "HI, please input the following: \n Hours -:";
    cin >> hour;
    cout << " Minutes -:";
    cin >> min;
    cout << " Seconds -:";
    cin >> sec;
    sec = ((hour*60)*60)+(min*60)+sec;
    cout << "The total is: " << sec << "s\n";
    return 0;
}