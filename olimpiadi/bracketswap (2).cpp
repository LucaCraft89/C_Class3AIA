// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    int R = 0;
    vector<int> A, B;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            if (A.size() < N / 2) {
                A.push_back(i);
            } else {
                B.push_back(i);
                R++;
            }
        } else {
            if (B.size() < N / 2) {
                B.push_back(i);
            } else {
                A.push_back(i);
                R++;
            }
        }
    }
    
    cout << R << '\n';
    for (int i = 0; i < R; i++) {
        cout << A[i] + 1 << " " << B[i] + 1 << '\n';
    }

    return 0;
}
