// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    int R = 0;
    
    vector<int> openIndices, closeIndices;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            openIndices.push_back(i);
        } else {
            closeIndices.push_back(i);
        }
    }
    
    int numSwaps = min(openIndices.size(), closeIndices.size());
    cout << numSwaps << '\n';
    for (int i = 0; i < numSwaps; i++) {
        cout << openIndices[i] << " " << closeIndices[i] << '\n';
    }

    

    return 0;
}
