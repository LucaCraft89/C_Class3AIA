//
// Created by lucac on 9/21/2023.
//
#include <iostream>

using namespace std;

int main() {
    int i = 0, count = 0;
    char word[200];
    cout << "input a string of text\n -:";
    cin >> word;
    while (i < 200) {
        count = count + 1;
        if (word[count] != NULL) {
            i=i+1;
        }
        else {
            break;
        }
    }
    cout << i+1;
    return 0;
}
