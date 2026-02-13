#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long b;
    cin >> n >> b;

    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    int totalMasks = 1 << n;
    vector<long long> subsetSum(totalMasks, 0);

    long long best = (long long)4e18;
    for (int mask = 1; mask < totalMasks; mask++) {
        int lb = mask & -mask;
        int bit = __builtin_ctz(lb);
        subsetSum[mask] = subsetSum[mask ^ lb] + h[bit];

        if (subsetSum[mask] >= b) {
            best = min(best, subsetSum[mask]);
        }
    }

    cout << (best - b) << '\n';
    return 0;
}
