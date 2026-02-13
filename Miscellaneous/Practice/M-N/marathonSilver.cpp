#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll manhattan(pair<int,int> &a, pair<int,int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> checkpoints(N);
    for (int i = 0; i < N; i++) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    // dp[i][k] = min distance to reach checkpoint i using exactly k skips
    vector<vector<ll>> dp(N, vector<ll>(K+1, INF));
    dp[0][0] = 0;

    for (int i = 1; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            // try skipping 0..k checkpoints between previous visited checkpoint and i
            for (int skip = 0; skip <= k; skip++) {
                int prev = i - skip - 1;
                if (prev >= 0) {
                    dp[i][k] = min(dp[i][k], dp[prev][k - skip] + manhattan(checkpoints[i], checkpoints[prev]));
                }
            }
        }
    }

    ll answer = INF;
    // minimum distance reaching last checkpoint with at most K skips
    for (int k = 0; k <= K; k++) {
        answer = min(answer, dp[N-1][k]);
    }

    cout << answer << endl;
    return 0;
}