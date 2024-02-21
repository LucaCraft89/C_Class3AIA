//
// Created by lucac on 2024/01/31.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const string fileName = "characters.txt";

struct Character
{
    string name;
    int level;
    string race;
    string characterClass;
};

void listCharacters(vector<Character>& players) {
    cout << "| Name\t| Level\t| Race\t| CharacterClass |\n";
    for (int i = 0; i < players.size(); i++) {  
        cout << "| " << players[i].name << "\t| " << players[i].level << "\t| " << players[i].race << "\t| " << players[i].characterClass << "\t|"<< endl;
    }
}

void sortByName(vector<Character>& players) {
    sort(players.begin(), players.end(), [](Character a, Character b) {
        return a.name < b.name;
    });
    cout << "Sorted by name" << endl;
    listCharacters(players);
}

void searchByName(vector<Character>& players) {
    sortByName(players);
    int left = 0;
    int right = players.size() - 1;
    string name;
    cout << "Enter name to search for\n -:";
    cin >> name;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (players[middle].name == name) {
            cout << "Found " << name << " at index " << middle << endl;
            cout << "| Name\t| Level\t| Race\t| CharacterClass |\n";
            cout << "| " << players[middle].name << "\t| " << players[middle].level << "\t| " << players[middle].race << "\t| " << players[middle].characterClass << "\t|"<< endl;
            return;
        }
        if (players[middle].name < name) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << "Could not find " << name << endl;
}

void addCharacter(vector<Character>& players){
    Character temp;
    cout << "Enter name\n -:";
    cin >> temp.name;
    cout << "Enter level\n -:";
    cin >> temp.level;
    cout << "Enter race\n -:";
    cin >> temp.race;
    cout << "Enter class\n -:";
    cin >> temp.characterClass;
    players.push_back(temp);
    cout << "Succesfuly added\n";
    cout << "| Name\t| Level\t| Race\t| CharacterClass |\n";
    cout << "| " << temp.name << "\t| " << temp.level << "\t| " << temp.race << "\t| " << temp.characterClass << "\t|"<< endl;
}

void writeToFIle(vector<Character>& players) {
    ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        for (int i = 0; i < players.size(); i++){
            file << players[i].name << " " << players[i].level << " " << players[i].race << " " << players[i].characterClass << endl;
        }
        file.close();
        cout << "Successfully saved to file" << endl;
        listCharacters(players);
    } else {
        cout << "Failed to open file" << endl;
    }
}

void readFromFile(vector<Character>& players) {
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            Character temp;
            file >> temp.name >> temp.level >> temp.race >> temp.characterClass;
            players.push_back(temp);
        }
        file.close();
        cout << "Successfully loaded from file" << endl;
        listCharacters(players);
    } else {
        cout << "Failed to open file" << endl;
    }
}



void gooodbye(string name) {
    cout << "Goodbye " << name << endl;
}

void menu() {
    cout << R"(
    1. Add a character
    2. Search for a character by name
    3. Sort characters by name
    4. Wirte to file
    5. Read from file
    6. ls characters
    0. Exit
    )";
    cout << "-: ";
}

string welcome() {
    cout << "Welcome to the character manager\n";
    cout << "Please enter your name or bank information: ";
    string name;
    cin >> name;
    cout << "Welcome " << name << endl << "Your name will not be used again, thanks anyways.\n";
    return name;
}



int main() {
    vector<Character> players;
    int sel;
    string usrName = welcome();
    do {
        menu();
        cin >> sel;
        switch (sel)
        {
        case 1:
            addCharacter(players);
            break;
        case 2:
            searchByName(players);
            break;
        case 3:
            sortByName(players);
            break;
        case 4:
            writeToFIle(players);
            break; 
        case 5:
            readFromFile(players);
            break;   
        case 6:
            listCharacters(players);
            break;   
        case 0:
            gooodbye(usrName);
            return 0;
            break;
        default:
            break;
        }
    } while (sel!=0);
    return 0;
}