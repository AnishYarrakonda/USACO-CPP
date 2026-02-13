#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> pref(n + 1, 0), suff(n + 2, 0);

    vector<int> st;
    st.reserve(26);
    for (int i = 1; i <= n; i++) {
        int h = s[i - 1] - 'A';
        while (!st.empty() && st.back() > h) {
            st.pop_back();
        }
        pref[i] = pref[i - 1];
        if (st.empty() || st.back() < h) {
            st.push_back(h);
            pref[i]++;
        }
    }

    st.clear();
    for (int i = n; i >= 1; i--) {
        int h = s[i - 1] - 'A';
        while (!st.empty() && st.back() > h) {
            st.pop_back();
        }
        suff[i] = suff[i + 1];
        if (st.empty() || st.back() < h) {
            st.push_back(h);
            suff[i]++;
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pref[a - 1] + suff[b + 1] << '\n';
    }

    return 0;
}
