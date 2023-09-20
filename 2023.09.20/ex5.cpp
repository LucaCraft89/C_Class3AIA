//
// Created by lucac on 9/20/2023.
//
#include <iostream>

using namespace std;

int main() {
    int basea, baseb, height, area;
    cout << "Welcome to the calculator of a trapezoid's area\nPlease provide the following values to continue\n First Base-:";
    cin >> basea;
    cout << " Second base-:";
    cin >> baseb;
    cout << " Height-:";
    cin >> height;
    area =  ((basea+baseb)*height)/2;
    cout << "The area of the trapezoid is: " << area << "cm2\n";
    return 0;
}
