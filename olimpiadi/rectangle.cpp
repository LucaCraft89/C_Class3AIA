#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findMaxRectangleArea(vector<int>& sticks) {
    int n = sticks.size();
    if (n < 4) {
        return 0; // Not enough sticks to form a rectangle
    }

    sort(sticks.begin(), sticks.end(), greater<int>()); // Sort the sticks in descending order

    long long maxArea = 0;

    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                if (sticks[i] == sticks[j] && sticks[k] == sticks[l]) {
                    long long area = static_cast<long long>(sticks[i]) * sticks[k];
                    maxArea = max(maxArea, area);
                    ++k;
                    --l;
                } else if (sticks[i] + sticks[j] > sticks[k] + sticks[l]) {
                    ++k;
                } else {
                    --l;
                }
            }
        }
    }

    return maxArea;
}

int main() {
    int N;
    cin >> N;

    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    long long maxArea = findMaxRectangleArea(S);
    cout << maxArea << endl;

    return 0;
}
