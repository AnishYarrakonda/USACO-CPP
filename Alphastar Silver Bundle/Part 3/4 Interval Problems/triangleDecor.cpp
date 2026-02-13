#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> intervals;

    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        long long L = x - y;
        long long R = x + y;
        intervals.push_back({L, R});
    }

    // Sort by L ascending, R descending
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    long long maxR = LLONG_MIN;
    int visible = 0;

    for (auto &[L, R] : intervals) {
        if (R > maxR) {
            visible++;
            maxR = R;
        }
    }

    cout << visible << "\n";
    return 0;
}
