// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, Q;
    cin >> N >> Q;
    
    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];
    
    vector<int> L(Q), R(Q), K(Q);
    for (int i = 0; i < Q; ++i)
        cin >> L[i] >> R[i] >> K[i];
    
    vector<int> ans(Q);
    
    for (int i = 0; i < Q; ++i) {
        vector<int> subarray(V.begin() + L[i], V.begin() + R[i] + 1);
        sort(subarray.rbegin(), subarray.rend());
        long long product = 1;
        for (int j = 0; j < K[i]; ++j) {
            product = (product * subarray[j]) % 1000000007;
        }
        ans[i] = product;
    }
    
    for (int i = 0; i < Q; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
