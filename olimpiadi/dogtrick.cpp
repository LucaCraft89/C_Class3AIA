// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> // Add this line to include the unordered_map library

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    
    int M;
    cin >> M;
    
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i)
        cin >> A[i] >> B[i];
    
    int P = 0;
    
    unordered_map<int, int> dp; // Use unordered_map instead of vector<vector<int>> to reduce memory usage
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (T[i] == A[j]) {
                if (dp.count(B[j]) > 0) {
                    dp[B[j]] = max(dp[B[j]], dp[A[j]] + 1);
                } else {
                    dp[B[j]] = dp[A[j]] + 1;
                }
            }
        }
        if (dp.count(T[i]) > 0) {
            P = max(P, dp[T[i]]);
        }
        if (i > 0 && T[i] != T[i-1] && dp.count(T[i-1]) == 0) {
            P = 0;
            break;
        }
    }
    
    cout << P << endl;

    return 0;
}
