#include <bits/stdc++.h>
using namespace std;

static bool wins(char b, char h) {
    return (b == 'P' && h == 'E') || (b == 'E' && h == 'T') || (b == 'T' && h == 'P');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<char> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    const string g = "PET";
    vector<vector<int>> pref(3, vector<int>(n + 1, 0));
    vector<vector<int>> suff(3, vector<int>(n + 2, 0));

    for (int t = 0; t < 3; t++) {
        for (int i = 1; i <= n; i++) {
            pref[t][i] = pref[t][i - 1] + (wins(g[t], h[i]) ? 1 : 0);
        }
    }

    for (int t = 0; t < 3; t++) {
        for (int i = n; i >= 1; i--) {
            suff[t][i] = suff[t][i + 1] + (wins(g[t], h[i]) ? 1 : 0);
        }
    }

    int best = 0;
    for (int split = 0; split <= n; split++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                best = max(best, pref[a][split] + suff[b][split + 1]);
            }
        }
    }

    cout << best << '\n';
    return 0;
}
