#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<long long, long long>& p) const {
        uint64_t x = static_cast<uint64_t>(p.first) ^ (static_cast<uint64_t>(p.first) >> 33);
        uint64_t y = static_cast<uint64_t>(p.second) ^ (static_cast<uint64_t>(p.second) >> 29);
        return static_cast<size_t>(x * 11995408973635179863ULL ^ (y + 0x9e3779b97f4a7c15ULL));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long xg, yg;
    cin >> xg >> yg;

    vector<pair<long long, long long>> instr(N);
    for (int i = 0; i < N; i++) {
        cin >> instr[i].first >> instr[i].second;
    }

    int n1 = N / 2;
    int n2 = N - n1;

    vector<unordered_map<pair<long long, long long>, long long, PairHash>> leftMaps(n1 + 1), rightMaps(n2 + 1);

    int lim1 = 1 << n1;
    for (int mask = 0; mask < lim1; mask++) {
        long long sx = 0, sy = 0;
        int k = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) {
                sx += instr[i].first;
                sy += instr[i].second;
                k++;
            }
        }
        leftMaps[k][{sx, sy}]++;
    }

    int lim2 = 1 << n2;
    for (int mask = 0; mask < lim2; mask++) {
        long long sx = 0, sy = 0;
        int k = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) {
                sx += instr[n1 + i].first;
                sy += instr[n1 + i].second;
                k++;
            }
        }
        rightMaps[k][{sx, sy}]++;
    }

    vector<long long> ans(N + 1, 0);

    for (int kl = 0; kl <= n1; kl++) {
        for (const auto& entry : leftMaps[kl]) {
            long long lx = entry.first.first;
            long long ly = entry.first.second;
            long long cntL = entry.second;

            long long needX = xg - lx;
            long long needY = yg - ly;

            for (int kr = 0; kr <= n2; kr++) {
                auto it = rightMaps[kr].find({needX, needY});
                if (it != rightMaps[kr].end()) {
                    ans[kl + kr] += cntL * it->second;
                }
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << ans[k] << "\n";
    }

    return 0;
}
