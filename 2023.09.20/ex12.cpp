//
// Created by lucac on 9/20/2023.
//
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    float cata, ipot, area, lenght, catb;
    cout << "Welcome to the square triangle calculator\nPlease provide the following information to continue:\nOne side-:";
    cin >> cata;
    cout << "Hypotenuse-:";
    cin >> ipot;
    catb=sqrt((pow(ipot, 2))- pow(cata, 2));
    lenght=cata+catb+ipot;
    area=(cata*catb)/2;
    cout << "Second Side: " << catb << "\nPerimeter: " << lenght << "\nSurface: " << area << "\n";

    return 0;
}
