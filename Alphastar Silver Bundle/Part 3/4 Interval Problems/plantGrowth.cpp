#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<pair<long long, long long>> events;
    events.reserve(2LL * N);

    for (int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;

        // At T = A, growth changes from X to Y.
        events.push_back({A, Y - X});
        // At T = B + 1, growth changes from Y to Z.
        events.push_back({B + 1, Z - Y});
    }

    sort(events.begin(), events.end());

    long long current = 1LL * N * X;  // For T smaller than every A(i).
    long long best = current;

    for (int i = 0; i < (int)events.size(); ) {
        int j = i;
        long long delta = 0;
        while (j < (int)events.size() && events[j].first == events[i].first) {
            delta += events[j].second;
            j++;
        }

        current += delta;
        best = max(best, current);
        i = j;
    }

    cout << best << "\n";
    return 0;
}
