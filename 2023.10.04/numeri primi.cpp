#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int tr=0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < sqrt(i); ++j) {
            if (i%j==0){
                tr=0;
            }
            else {
                tr=1;
            }
        }
        if (tr){
            cout << i;
        }
    }
    return 0;
}
