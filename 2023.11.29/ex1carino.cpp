//
// Created by lucac on 11/29/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const string path = "C:\\Users\\lucac\\CLionProjects\\C_Class3AIA\\2023.11.29\\words.txt";

void hang0(){
    cout << R"(
  +---+
  |   |
      |
      |
      |
      |
=========
)";
}
void hang1(){
    cout << R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========
)";
}
void hang2(){
    cout << R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)";
}
void hang3(){
    cout << R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)";
}
void hang4(){
    cout << R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)";
}
void hang5(){
    cout << R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)";
}
void hang6(){
    cout << R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)";
}

void hang(int state) {
    switch (state) {
        case 0:
            hang0();
            break;
        case 1:
            hang1();
            break;
        case 2:
            hang2();
            break;
        case 3:
            hang3();
            break;
        case 4:
            hang4();
            break;
        case 5:
            hang5();
            break;
        case 6:
            hang6();
            break;
        default:
            cout << "ehe?";
    }
}

void outWord(std::string& word, int  letters[200], int& f)
{
    for (int j = 1; j < word.length(); j++) {
        if (j == letters[j]) {
            cout << word[j] << " ";
            f++;
        }
        else {
            cout << "_ ";
        }
    }
}

void goodLetters(std::string& word, char guess, int  letters[200], int& state, int& n)
{
    for (int j = 1; j < word.length(); j++) {
        if (guess == word[j]) {
            letters[j] = j;
            state--;
            n = 0;
        }
        else {
            n = 1;
        }
    }
}

int main() {
    //system("mode con:cols=50 lines=11");
    string word, line, lines[200];
    char guess;
    int state = 0, letters[200], f = 0, n = 0, out = 0, k=0;
    ifstream myFile(path);
    if (myFile.is_open())
    {
        while (getline(myFile,line)){
            lines[k]=line;
            k++;
        }
        myFile.close();
    }
    else {
        cout << "unable file\n";
    }
    for (int i = 0; i < size(letters); i++) {
        letters[i] = -1;
    }
    srand(time(NULL));
    word=lines[rand()%6];
    /*
    cout << "Immettere parola\n -:";
    fflush(stdin);
    getline(cin, word);
     */
    while(out!=1) {
        hang(state);
        cout << word[0] << " ";
        f = 0;
        outWord(word, letters, f);
        cout << endl;
        if (f + 1 == word.length()) {
            cout << "hai vinto!!!\n";
            return 1;
        }
        cout << "immettre lettera\n -:";
        cin >> guess;
        goodLetters(word, guess, letters, state, n);
        if (n == 1) {
            state++;
        }
        if (state > 5){
            out=1;
        }
    }
    cout << "hai preso||\n";
    return 0;
}
