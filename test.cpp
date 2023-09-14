//
// Created by lucac on 9/14/2023.
//
#include <iostream>

using namespace std;

class Human {
private:
    class Brain { ;
    public:
        void Think() {
            cout << "blyat";
        }
    };
public:
    int age;
    float wight;
    Brain humanbrain;
};

int main() {
    Human o;
    o.humanbrain;
    o.humanbrain.Think();
    return 0;
}

