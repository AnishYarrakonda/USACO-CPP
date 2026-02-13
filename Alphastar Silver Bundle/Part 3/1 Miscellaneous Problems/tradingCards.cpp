#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    vector<int> A(N);
    for (int &x : A) cin >> x;
    sort(A.rbegin(), A.rend());

    auto can = [&](int r) {
        long long need = 0;
        for (int i = 0; i < r; i++) {
            if (A[i] + K < r) return false;
            need += max(0, r - A[i]);
        }
        return need <= (long long)K * L;
    };

    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (can(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
}