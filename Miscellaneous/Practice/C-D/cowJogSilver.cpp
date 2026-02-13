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

    ll N, T;
    cin >> N >> T;
    vector<pair<ll,ll>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    vector<ll> finalPos(N);
    for (int i = 0; i < N; i++) {
        finalPos[i] = cows[i].first + cows[i].second * T;
    }

    vector<ll> pos(N);
    pos[N-1] = finalPos[N-1];
    for (int i = N-2; i >= 0; i--) {
        pos[i] = min(finalPos[i], pos[i+1]);
    }

    int groups = 1;
    for (int i = 1; i < N; i++) {
        if (pos[i] != pos[i-1]) groups++;
    }

    cout << groups << endl;
    return 0;
}
