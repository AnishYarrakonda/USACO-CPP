#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int N; int K; cin >> N >> K;
    vector<int> diamonds;
    for (int i = 0; i < N; i++) {
        int size; cin >> size;
        diamonds.push_back(size);
    }
    sort(diamonds.begin(), diamonds.end());

    int maxNum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (diamonds[j] - diamonds[i] <= K) {
                maxNum = max(maxNum, j-i+1);
            }
        }
    }

    cout << maxNum << endl;

    return 0;
}