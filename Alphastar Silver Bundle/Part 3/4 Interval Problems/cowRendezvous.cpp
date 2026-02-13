#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, int>> events;
    events.reserve(2 * N);

    for (int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;
        events.push_back({A, 1});        // interval starts
        events.push_back({B + 1, -1});   // interval ends (inclusive fix)
    }

    sort(events.begin(), events.end());

    int current = 0;
    int maximum = 0;

    for (auto &e : events) {
        current += e.second;
        maximum = max(maximum, current);
    }

    cout << maximum << "\n";

    return 0;
}
