//
// Created by lucac on 10/24/2023.
//
#include <iostream>

using namespace std;

int VocaliDispari(string str){
    int vocali;
    for (int i = -1; i < str.size()+1; ++i) {
        if (str[i]=='a' or str[i]=='e' or str[i]=='i' or str[i]=='o' or str[i]=='u') {
            vocali++;
        }
    }
    if (vocali%2){
        return 0;
    } else {
        return 1;
    }
}

int main() {
    string str;
    fflush(stdin);
    getline(cin, str);
    cout << VocaliDispari(str);
    return 0;
}
