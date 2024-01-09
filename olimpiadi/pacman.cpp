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

    vector<int> X(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i];

    vector<int> Y(N);
    for (int i = 0; i < N; ++i)
        cin >> Y[i];

    vector<int> Z(N);
    for (int i = 0; i < N; ++i)
        cin >> Z[i];

    bool success = false;


    // INSERT YOUR CODE HERE


    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
