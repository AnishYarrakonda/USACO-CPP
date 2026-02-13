#include <bits/stdc++.h>
using namespace std;

struct FenwickMin {
    int n;
    vector<int> bit;

    explicit FenwickMin(int n) : n(n), bit(n + 1, INT_MAX) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] = min(bit[idx], val);
        }
    }

    int query(int idx) const {
        int res = INT_MAX;
        for (; idx > 0; idx -= idx & -idx) {
            res = min(res, bit[idx]);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, char>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());

    vector<int> x(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        x[i] = cows[i - 1].first;
        int val = (cows[i - 1].second == 'H') ? 1 : -1;
        pref[i] = pref[i - 1] + val;
    }

    vector<int> all = pref;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto idxOf = [&](int v) {
        return int(lower_bound(all.begin(), all.end(), v) - all.begin()) + 1;
    };

    FenwickMin fwEven((int)all.size()), fwOdd((int)all.size());

    auto parity = [&](int v) {
        int p = v % 2;
        if (p < 0) p += 2;
        return p;
    };

    int firstIdx = idxOf(pref[0]);
    if (parity(pref[0]) == 0) {
        fwEven.update(firstIdx, x[1]);
    } else {
        fwOdd.update(firstIdx, x[1]);
    }

    int ans = 0;

    for (int j = 1; j <= n; j++) {
        int curIdx = int(upper_bound(all.begin(), all.end(), pref[j]) - all.begin());
        int bestStart = (parity(pref[j]) == 0) ? fwEven.query(curIdx) : fwOdd.query(curIdx);

        if (bestStart != INT_MAX) {
            ans = max(ans, x[j] - bestStart);
        }

        if (j + 1 <= n) {
            int insIdx = idxOf(pref[j]);
            if (parity(pref[j]) == 0) {
                fwEven.update(insIdx, x[j + 1]);
            } else {
                fwOdd.update(insIdx, x[j + 1]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
