#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> d(N);
    long long mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> d[i];
        mx = max(mx, d[i]);
    }

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    long long T = ((mx + 11) / 12) * 12; // first jump destination

    vector<long long> pts;
    pts.reserve(d.size() + 2);
    pts.push_back(0);
    for (long long x : d) pts.push_back(x);
    pts.push_back(T);

    vector<long long> gains;
    gains.reserve((int)pts.size() - 1);

    for (int i = 0; i + 1 < (int)pts.size(); i++) {
        long long L = pts[i];
        long long R = pts[i + 1];

        long long low = ((L + 11) / 12) * 12; // smallest multiple >= L
        long long high = (R / 12) * 12;       // largest multiple <= R

        long long g = 0;
        if (high > low) g = high - low;
        gains.push_back(g);
    }

    sort(gains.rbegin(), gains.rend());

    long long saved = 0;
    int canUse = min((int)gains.size(), K - 1);
    for (int i = 0; i < canUse; i++) {
        if (gains[i] <= 0) break;
        saved += gains[i];
    }

    long long answer = T - saved;
    cout << answer << "\n";
    return 0;
}
