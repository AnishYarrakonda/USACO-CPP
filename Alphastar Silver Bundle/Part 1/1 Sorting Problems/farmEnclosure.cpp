#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pi> pts(N);
    for (auto &p : pts) cin >> p.first >> p.second;

    vector<pi> byX = pts, byY = pts;
    sort(byX.begin(), byX.end());
    sort(byY.begin(), byY.end(),
         [](auto &a, auto &b){ return a.second < b.second; });

    // Collect candidates
    set<pi> cand;
    for (int i = 0; i < min(4, N); i++) {
        cand.insert(byX[i]);
        cand.insert(byX[N-1-i]);
        cand.insert(byY[i]);
        cand.insert(byY[N-1-i]);
    }

    vector<pi> C(cand.begin(), cand.end());
    int M = C.size();

    ll ans = LLONG_MAX;

    // Try all subsets up to size 3
    for (int mask = 0; mask < (1<<M); mask++) {
        if (__builtin_popcount(mask) > 3) continue;

        ll minx = LLONG_MAX, maxx = LLONG_MIN;
        ll miny = LLONG_MAX, maxy = LLONG_MIN;

        for (auto &p : pts) {
            bool removed = false;
            for (int i = 0; i < M; i++) {
                if ((mask & (1<<i)) && p == C[i]) {
                    removed = true;
                    break;
                }
            }
            if (removed) continue;

            minx = min(minx, (ll)p.first);
            maxx = max(maxx, (ll)p.first);
            miny = min(miny, (ll)p.second);
            maxy = max(maxy, (ll)p.second);
        }

        if (minx == LLONG_MAX) continue; // all removed

        ans = min(ans, (maxx - minx) * (maxy - miny));
    }

    cout << ans << "\n";
    return 0;
}
