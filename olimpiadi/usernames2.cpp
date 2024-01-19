// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isUsernameAvailable(const unordered_set<string>& usernames, const string& username) {
    return usernames.find(username) == usernames.end();
}

string generateUsername(const unordered_set<string>& usernames, const string& baseUsername) {
    string username = baseUsername;
    int number = 1;
    while (!isUsernameAvailable(usernames, username)) {
        username = baseUsername + to_string(number);
        number++;
    }
    return username;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    string S;
    cin >> S;
    
    int N;
    cin >> N;
    
    unordered_set<string> U;
    for (int i = 0; i < N; ++i) {
        string username;
        cin >> username;
        U.insert(username);
    }
    
    string T = generateUsername(U, S);
    
    cout << T << endl;

    return 0;
}
