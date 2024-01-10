//
// Created by lucac on 11/21/2023.
//
#include <iostream>

using namespace std;

bool hasConsecutiveLetters(string str) {
    int c=1;
    for (int i = 1; i < str.length(); ++i){
        if (str[i] == str[i-1]){
            c++;
            if (c>=3){
                return true;
            }
        } else {
            c=1;
        }
    }
    return false;
}

bool hasAlphabeticOrder(string str) {
    int c=1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == str[i-1]+1) {
            c++;
            if (c>=3){
                return true;
            }
        } else {
            c=1;
        }
    }
    return false;
}

bool isGood(string str){
    if (hasConsecutiveLetters(str)==0 and hasAlphabeticOrder(str)==0){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string str;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        fflush(stdin);
        getline(cin, str);
        if (isGood(str)){
            cout << "Bona\n";
        } else {
            cout << "Cattiva\n"
        }
    }
    return 0;
}
