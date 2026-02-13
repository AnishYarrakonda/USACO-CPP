#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> suffSum(n + 1, 0);
    vector<long long> suffMin(n + 1, (long long)4e18);

    for (int i = n - 1; i >= 0; i--) {
        suffSum[i] = suffSum[i + 1] + a[i];
        suffMin[i] = min(suffMin[i + 1], a[i]);
    }

    long long bestNum = -1;
    long long bestDen = 1;
    vector<int> ans;

    for (int k = 1; k <= n - 2; k++) {
        int i = k;
        long long num = suffSum[i] - suffMin[i];
        long long den = n - i - 1;

        if (bestNum == -1 || num * bestDen > bestNum * den) {
            bestNum = num;
            bestDen = den;
            ans.clear();
            ans.push_back(k);
        } else if (num * bestDen == bestNum * den) {
            ans.push_back(k);
        }
    }

    for (int k : ans) {
        cout << k << '\n';
    }

    return 0;
}
