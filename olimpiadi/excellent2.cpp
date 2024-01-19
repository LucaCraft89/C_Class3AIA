// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N;
        cin >> N;
        
        vector<int> dp(3, 0);
        dp[0] = 1; // base case
        
        vector<int> remainderLookup = {1, 0, 2}; // lookup table for remainder calculation
        
        for (int i = 1; i <= N; ++i) {
            vector<int> new_dp(3, 0);
            for (int j = 0; j < 3; ++j) {
                for (int k = 1; k <= 5; k += 4) {
                    int remainder = remainderLookup[j + k];
                    new_dp[remainder] = (new_dp[remainder] + dp[j]) % MOD;
                }
            }
            dp = new_dp;
        }
        
        int ans = dp[0];
        
        cout << ans << endl;
    }

    return 0;
}
