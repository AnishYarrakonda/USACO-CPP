#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string S;
ll L;

char backtrack(ll x) {
    if (x <= L) {
        return S[x];
    }

    ll split = (ll)log2((x - 1) / L);
    ll block_len = L * (1LL << split);

    if (x == block_len + 1) {
        return backtrack(x - 1);
    } else {
        return backtrack(x - block_len - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> S >> N;

    S = " " + S;
    L = (ll)S.size() - 1;

    cout << backtrack(N) << '\n';
    return 0;
}
