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

int main() {
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    map<pair<char,char>,int> MOOs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // North
            if (i >= 2) {
                if (grid[i][j] != grid[i-1][j] && grid[i-1][j] == grid[i-2][j]) {
                    MOOs.insert({{grid[i][j], grid[i-1][j]}, 0});
                    MOOs[{grid[i][j], grid[i-1][j]}] += 1;
                }
            }
            // South
            if (i <= N-3) {
                if (grid[i][j] != grid[i+1][j] && grid[i+1][j] == grid[i+2][j]) {
                    MOOs.insert({{grid[i][j], grid[i+1][j]}, 0});
                    MOOs[{grid[i][j], grid[i+1][j]}] += 1;
                }
            }
            // East
            if (j <= M-3) {
                if (grid[i][j] != grid[i][j+1] && grid[i][j+1] == grid[i][j+2]) {
                    MOOs.insert({{grid[i][j], grid[i][j+1]}, 0});
                    MOOs[{grid[i][j], grid[i][j+1]}] += 1;
                }
            }
            // West
            if (j >= 2) {
                if (grid[i][j] != grid[i][j-1] && grid[i][j-1] == grid[i][j-2]) {
                    MOOs.insert({{grid[i][j], grid[i][j-1]}, 0});
                    MOOs[{grid[i][j], grid[i][j-1]}] += 1;
                }
            }
            // NW
            if (i >= 2 && j >= 2) {
                if (grid[i][j] != grid[i-1][j-1] && grid[i-1][j-1] == grid[i-2][j-2]) {
                    MOOs.insert({{grid[i][j], grid[i-1][j-1]}, 0});
                    MOOs[{grid[i][j], grid[i-1][j-1]}] += 1;
                }
            }
            // NE
            if (i >= 2 && j <= M-3) {
                if (grid[i][j] != grid[i-1][j+1] && grid[i-1][j+1] == grid[i-2][j+2]) {
                    MOOs.insert({{grid[i][j], grid[i-1][j+1]}, 0});
                    MOOs[{grid[i][j], grid[i-1][j+1]}] += 1;
                }
            }
            // SE
            if (i <= N-3 && j <= M-3) {
                if (grid[i][j] != grid[i+1][j+1] && grid[i+1][j+1] == grid[i+2][j+2]) {
                    MOOs.insert({{grid[i][j], grid[i+1][j+1]}, 0});
                    MOOs[{grid[i][j], grid[i+1][j+1]}] += 1;
                }
            }
            // SW
            if (i <= N-3 && j >= 2) {
                if (grid[i][j] != grid[i+1][j-1] && grid[i+1][j-1] == grid[i+2][j-2]) {
                    MOOs.insert({{grid[i][j], grid[i+1][j-1]}, 0});
                    MOOs[{grid[i][j], grid[i+1][j-1]}] += 1;
                }
            }
        }
    }

    int totalMoos = 0;
    for (auto [chars, moos] : MOOs) {
        if (chars.first == 'M' || chars.second == 'O') continue;
        totalMoos = max(moos, totalMoos);
    }
    
    cout << totalMoos << endl;

    return 0;
}