#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int initial = 0;
    for (int i = 0; i < 20; i++) {
        int x;
        cin >> x;
        if (x == 1) initial |= (1 << i);
    }

    vector<int> toggle(20, 0);
    for (int i = 0; i < 20; i++) {
        int mask = 0;
        if (i - 1 >= 0) mask |= (1 << (i - 1));
        mask |= (1 << i);
        if (i + 1 < 20) mask |= (1 << (i + 1));
        toggle[i] = mask;
    }

    int totalMasks = 1 << 20;
    vector<int> effect(totalMasks, 0);

    int best = INT_MAX;
    for (int mask = 1; mask < totalMasks; mask++) {
        int lb = mask & -mask;
        int bit = __builtin_ctz(lb);
        effect[mask] = effect[mask ^ lb] ^ toggle[bit];

        if (effect[mask] == initial) {
            best = min(best, __builtin_popcount((unsigned)mask));
        }
    }

    if (initial == 0) best = 0;
    cout << best << '\n';
    return 0;
}
