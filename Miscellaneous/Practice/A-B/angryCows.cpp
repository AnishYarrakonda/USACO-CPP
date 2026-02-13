#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    sort(H.begin(), H.end());
    int max_exploded = 0;

    for (int start = 0; start < N; start++) {
        int exploded = 1;

        int left = start;
        int radius = 1;
        while (left > 0) {
            int new_left = left;
            for (int i = left - 1; i >= 0; i--) {
                if (H[left] - H[i] <= radius) new_left = i;
                else break;
            }
            if (new_left == left) break;
            exploded += left - new_left;
            left = new_left;
            radius++;
        }

        int right = start;
        radius = 1;
        while (right < N - 1) {
            int new_right = right;
            for (int i = right + 1; i < N; i++) {
                if (H[i] - H[right] <= radius) new_right = i;
                else break;
            }
            if (new_right == right) break;
            exploded += new_right - right;
            right = new_right;
            radius++;
        }

        max_exploded = max(max_exploded, exploded);
    }

    cout << max_exploded << endl;
    return 0;
}
