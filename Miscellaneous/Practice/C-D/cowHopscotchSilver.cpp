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
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    int R, C, K; cin >> R >> C >> K;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    const int MOD = 1e9+7;
    vector<vint> dp(R, vint(C, 0)); dp[0][0] = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int x = i+1; x < R; x++) {
                for (int y = j+1; y < C; y++) {
                    if (grid[i][j] != grid[x][y]) {
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[R-1][C-1] << endl;

    return 0;
}