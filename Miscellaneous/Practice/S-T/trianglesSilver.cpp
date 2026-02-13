#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    
    int N; fin >> N;

    vector<pii> allPoints(N);

    map<int, vint> Xpoints;  // x -> list of y's
    map<int, vint> Ypoints;  // y -> list of x's
    
    for (int i = 0; i < N; i++) {
        int x, y; fin >> x >> y;
        Xpoints[x].push_back(y);
        Ypoints[y].push_back(x);  // FIX: was Xpoints[y]
        allPoints[i] = {x, y};
    }

    // Compute sum_y for each point: sum of |y' - y| for all y' with same x
    map<pii, ll> sum_y;
    for (auto& [x, ys] : Xpoints) {
        sort(ys.begin(), ys.end());
        int n = ys.size();
        
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + ys[i];
        }
        
        for (int i = 0; i < n; i++) {
            ll left_sum = (ll)i * ys[i] - prefix[i];
            ll right_sum = (prefix[n] - prefix[i + 1]) - (ll)(n - i - 1) * ys[i];
            sum_y[{x, ys[i]}] = left_sum + right_sum;
        }
    }

    // Compute sum_x for each point: sum of |x' - x| for all x' with same y
    map<pii, ll> sum_x;
    for (auto& [y, xs] : Ypoints) {
        sort(xs.begin(), xs.end());
        int n = xs.size();
        
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + xs[i];
        }
        
        for (int i = 0; i < n; i++) {
            ll left_sum = (ll)i * xs[i] - prefix[i];
            ll right_sum = (prefix[n] - prefix[i + 1]) - (ll)(n - i - 1) * xs[i];
            sum_x[{xs[i], y}] = left_sum + right_sum;
        }
    }

    // Compute answer: multiply sum_x * sum_y for each point
    ll ans = 0;
    for (auto [x, y] : allPoints) {
        ll sx = sum_x[{x, y}];
        ll sy = sum_y[{x, y}];
        ll contribution = (sx % MOD) * (sy % MOD) % MOD;
        ans = (ans + contribution) % MOD;
    }

    fout << ans << "\n";

    return 0;
}