#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    // Sort trees by x-coordinate
    sort(trees.begin(), trees.end());

    int answer = INT_MAX;

    // Try each vertical cut position
    for (int i = 0; i < N; i++) {
        int a = trees[i].first + 1; // even cut

        vector<int> leftY, rightY;

        // Split trees into left / right
        for (auto &t : trees) {
            if (t.first < a) leftY.push_back(t.second);
            else rightY.push_back(t.second);
        }

        sort(leftY.begin(), leftY.end());
        sort(rightY.begin(), rightY.end());

        int TL = leftY.size(), BL = 0;
        int TR = rightY.size(), BR = 0;

        int li = leftY.size() - 1;
        int ri = rightY.size() - 1;

        // Sweep horizontal cut from top → bottom
        while (li >= 0 || ri >= 0) {
            int nextY;

            if (ri < 0 || (li >= 0 && leftY[li] > rightY[ri]))
                nextY = leftY[li];
            else
                nextY = rightY[ri];

            while (li >= 0 && leftY[li] == nextY) {
                TL--;
                BL++;
                li--;
            }
            while (ri >= 0 && rightY[ri] == nextY) {
                TR--;
                BR++;
                ri--;
            }

            answer = min(answer, max({TL, TR, BL, BR}));
        }
    }

    cout << answer << "\n";
}
