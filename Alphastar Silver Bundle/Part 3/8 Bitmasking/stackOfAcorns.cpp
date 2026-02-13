#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second; // width, depth
    }

    sort(a.begin(), a.end(), [&](const auto& x, const auto& y) {
        return x.first > y.first; // descending width
    });

    int totalMasks = 1 << n;
    int best = 0;

    for (int mask = 1; mask < totalMasks; mask++) {
        int cnt = __builtin_popcount((unsigned)mask);
        if (cnt <= best) continue;

        bool ok = true;
        int lastWidth = INT_MAX;
        int lastDepth = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (a[i].first >= lastWidth || a[i].second >= lastDepth) {
                    ok = false;
                    break;
                }
                lastWidth = a[i].first;
                lastDepth = a[i].second;
            }
        }

        if (ok) best = cnt;
    }

    cout << best << '\n';
    return 0;
}
