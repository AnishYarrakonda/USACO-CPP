#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    int N; cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<pii> cows;
    for (int i = 0; i < N; i++) {
        int p, s; cin >> p >> s;
        cows.push_back({p, s});
    }

    int groups = 1;
    for (int i = N-2; i >= 0; i--) {
        if (cows[i].second <= cows[i+1].second) {
            groups++;
        } else cows[i].second = cows[i+1].second;
    }
    cout << groups << endl;

    return 0;
}