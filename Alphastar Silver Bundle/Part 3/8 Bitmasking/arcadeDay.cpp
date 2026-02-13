#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 12;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int allMask = (1 << n) - 1;
    vector<int> sumMask(1 << n, 0);
    vector<char> isTriple(1 << n, 0);
    vector<int> triples;

    for (int mask = 0; mask <= allMask; mask++) {
        if (__builtin_popcount((unsigned)mask) == 3) {
            isTriple[mask] = 1;
            triples.push_back(mask);
            int total = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) total += s[i];
            }
            sumMask[mask] = total;
        }
    }

    int answer = INT_MAX;

    for (int m1 : triples) {
        if ((m1 & 1) == 0) continue; // force player 0 in first team

        int rem1 = allMask ^ m1;
        int firstRem1 = __builtin_ctz(rem1);

        for (int m2 : triples) {
            if ((m2 & rem1) != m2) continue;
            if ((m2 & (1 << firstRem1)) == 0) continue; // canonicalize second team

            int rem2 = rem1 ^ m2;
            int firstRem2 = __builtin_ctz(rem2);

            for (int m3 : triples) {
                if ((m3 & rem2) != m3) continue;
                if ((m3 & (1 << firstRem2)) == 0) continue; // canonicalize third team

                int m4 = rem2 ^ m3;
                if (!isTriple[m4]) continue;

                int s1 = sumMask[m1];
                int s2 = sumMask[m2];
                int s3 = sumMask[m3];
                int s4 = sumMask[m4];

                int mx = max(max(s1, s2), max(s3, s4));
                int mn = min(min(s1, s2), min(s3, s4));
                answer = min(answer, mx - mn);
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
