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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

int mod;

bool comp(int a, int b) {
    return (a%mod) > (b%mod);
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    int N, K; cin >> N >> K;
    vint A(N); int M = 0;
	for(int i=0;i<N;i++) {cin >> A[i]; M = max(M, A[i]);}

    int best = 0;
    for (int b = 1; b <= M; b++) {
        int full = 0;
        for (int i = 0; i < N; i++) full += A[i] / b;
        if (full < K/2) break;
        if (full >= K) {
            best = max(best, b*(K/2));
			continue;
        }
        mod = b;
        sort(A.begin(), A.end(), comp);
        int cur = b*(full - K/2);
        for (int i = 0; i < N && i + full < K; i++) cur += A[i] % b;
        best = max(best, cur);
    }
    
    cout << best << '\n';

    return 0;
}