//
// Created by lucac on 2024/01/23.
//
#include <iostream>
#include <fstream>

using namespace std;

const int MAXp=10;
const string fileName = "collection.pok";

struct pokemon
{
    string name;
    string type;
    int level;
    int hp;
};

bool pokemonexists(string name, pokemon p[]) {
    for (int i = 0; i < MAXp; i++) {
        if (p[i].name == name) {
            return true;
        }
    }
    return false;
}

void capturePokemon(string name, string type, int level, int hp, pokemon p[]) {
    for (int i = 0; i < MAXp; i++) {
        if (p[i].name == "") {
            if (pokemonexists(name, p)) {
                cout << "Pokemon already exists" << endl;
                return;
            }
            p[i].name = name;
            p[i].type = type;
            p[i].level = level;
            p[i].hp = hp;
            break;
        }
    }
}

void listPokemon(pokemon p[]) {
    cout << "[| N | Name\t| Type\t| Level\t| HP |]" << endl;
    for (int i = 0; i < MAXp; i++) {
        if (p[i].name != "") {
            cout << " | " << i+1 << " | " << p[i].name << "\t| " << p[i].type << "\t| " << p[i].level << "\t| " << p[i].hp << "  |" << endl;
        }
    }
}

int countPokemon(pokemon p[]) {
    int n = 0;
    for (int i = 0; i < MAXp; i++) {
        if (p[i].name != "") {
            n++;
        }
    }
    return n;
}

void saveCollection(pokemon p[]) {
    ofstream file;
    file.open(fileName);
    for (int i = 0; i < MAXp; i++) {
        if (p[i].name != "") {
            file << p[i].name << " " << p[i].type << " " << p[i].level << " " << p[i].hp << endl;
        }
    }
    file.close();
    int n = 0;
    n = countPokemon(p);
    cout << "Collection saved" << endl;
    cout << "Saved " << n << " pokemon" << endl;
}

void loadCollection(pokemon p[]) {
    ifstream file;
    file.open(fileName);
    string name, type;
    int level, hp;
    while (file >> name >> type >> level >> hp) {
        capturePokemon(name, type, level, hp, p);
    }
    file.close();
    int n = 0;
    n = countPokemon(p);
    cout << "Collection loaded" << endl;
    cout << "Loaded " << n << " pokemon" << endl;
}

void deletePokemon(int n, pokemon p[]) {
    p[n-1].name = "";
    p[n-1].type = "";
    p[n-1].level = 0;
    p[n-1].hp = 0;
}

void editPokemon(int n, pokemon p[]) {
    string name, type;
    int level, hp;
    cout << "Name\n -: ";
    cin >> name;
    cout << "Type\n -: ";
    cin >> type;
    cout << "Level\n -: ";
    cin >> level;
    cout << "HP\n -: ";
    cin >> hp;
    capturePokemon(name, type, level, hp, p);
    deletePokemon(n, p);
}

int main() {
    pokemon p[MAXp];
    int choice;
    string name, type;
    int level, hp;
    do {
        cout << R"(
==================================
           POKEMON MENU
==================================
1. Capture a new pokemon
2. List all pokemon
3. Save collection
4. Load collection
5. Delete pokemon
6. Edit pokemon
0. Exit
==================================
)";
        cout << "Choice\n -: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Name\n -: ";
            cin >> name;
            cout << "Type\n -: ";
            cin >> type;
            cout << "Level\n -: ";
            cin >> level;
            cout << "HP\n -: ";
            cin >> hp;
            capturePokemon(name, type, level, hp, p);
            break;
        case 2:
            listPokemon(p);
            break;
        case 3:
            saveCollection(p);
            break;
        case 4:
            loadCollection(p);
            break;
        case 5:
            int n;
            cout << "Pokemon to delete\n -: ";
            cin >> n;
            deletePokemon(n, p);
            break;
        case 6:
            int m;
            cout << "Pokemon to edit\n -: ";
            cin >> m;
            editPokemon(m, p);
            break;
        case 0:
            saveCollection(p);
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}