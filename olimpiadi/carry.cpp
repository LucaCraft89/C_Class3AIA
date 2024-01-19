// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSumLessThan2L(const string& A, const string& B, int X, int Y, int L) {
        string subA = A.substr(X, L);
        string subB = B.substr(Y, L);

        int numA = stoi(subA, nullptr, 2);
        int numB = stoi(subB, nullptr, 2);

        int sum = numA + numB;

        return sum < (1 << L);
    }   

    int main() {
        int N;
        cin >> N;
        
        string A;
        cin >> A;
        
        string B;
        cin >> B;
        
        int Q;
        cin >> Q;
        
        vector<int> X(Q), Y(Q), L(Q);
        for (int i = 0; i < Q; ++i)
            cin >> X[i] >> Y[i] >> L[i];
        
        vector<int> ans(Q);
        for (int i = 0; i < Q; ++i)
            ans[i] = isSumLessThan2L(A, B, X[i], Y[i], L[i]);
        
        for (int i = 0; i < Q; ++i)
            cout << ans[i] << " ";
        cout << endl;

        return 0;
    }
