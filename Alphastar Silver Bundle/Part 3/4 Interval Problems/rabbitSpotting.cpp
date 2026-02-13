#include <bits/stdc++.h>
using namespace std;

static long long countInRange(long long L, long long R, long long A, long long B) {
    long long left = max(L, A);
    long long right = min(R, B);
    if (left > right) return 0;
    return right - left + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long A, B;
    cin >> N >> A >> B;

    vector<pair<long long, bool>> rabbits;
    rabbits.reserve(N);

    for (int i = 0; i < N; i++) {
        string type;
        long long w;
        cin >> type >> w;
        rabbits.push_back({w, type == "S"});
    }

    sort(rabbits.begin(), rabbits.end());

    // Merge equal weights; if any rabbit at that weight is spotted, treat that weight as spotted.
    vector<long long> w;
    vector<bool> spotted;
    for (int i = 0; i < N; ) {
        int j = i;
        bool anySpotted = false;
        while (j < N && rabbits[j].first == rabbits[i].first) {
            anySpotted = anySpotted || rabbits[j].second;
            j++;
        }
        w.push_back(rabbits[i].first);
        spotted.push_back(anySpotted);
        i = j;
    }

    int M = (int)w.size();

    if (M == 1) {
        cout << (spotted[0] ? (B - A + 1) : 0) << "\n";
        return 0;
    }

    long long ans = 0;
    const long long NEG_INF = LLONG_MIN / 4;
    const long long POS_INF = LLONG_MAX / 4;

    // Count strict-nearest regions (no tie points).
    for (int i = 0; i < M; i++) {
        long long L, R;

        if (i == 0) {
            L = NEG_INF;
            R = (w[0] + w[1] - 1) / 2;
        } else if (i == M - 1) {
            L = (w[M - 2] + w[M - 1] + 2) / 2;
            R = POS_INF;
        } else {
            L = (w[i - 1] + w[i] + 2) / 2;
            R = (w[i] + w[i + 1] - 1) / 2;
        }

        if (spotted[i]) {
            ans += countInRange(L, R, A, B);
        }
    }

    // Count tie points between consecutive distinct weights.
    for (int i = 0; i + 1 < M; i++) {
        long long sum = w[i] + w[i + 1];
        if (sum % 2 == 0) {
            long long mid = sum / 2;
            if (A <= mid && mid <= B && (spotted[i] || spotted[i + 1])) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
