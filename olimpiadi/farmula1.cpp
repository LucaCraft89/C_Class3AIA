// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int points(int pos){
    switch (pos) {
        case 1:
            return 25;
        case 2:
            return 18;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 10;
        case 6:
            return 8;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        default:
            return 0;
    }
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; ++i){
            cin >> P[i];
        }
        
        string ans = "";
        int on=0;
        for (int i = 0; i < N; i++) {
            if (P[i]==1){
                on++;
            }
        }
        if (N%2==0){
            if (on>=int(N/2)){
                ans = "Champion";
            } else {
                ans = "Practice harder";
            }
        } else {
            if (on>int(N/2)){
                ans = "Champion";
            } else {
                ans = "Practice harder";
            }
        }

        
        cout << ans << endl;
    }

    return 0;
}
