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

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];
        
        string ans = "";
        
        
        // INSERT YOUR CODE HERE
        
        
        cout << ans << endl;
    }

    return 0;
}
