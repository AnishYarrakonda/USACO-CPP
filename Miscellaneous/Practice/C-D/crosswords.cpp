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


bool isClue(int x, int y, const vector<vector<char>>& grid, int N, int M) {
    return grid[x][y] == '.' &&
       (
           ((y-1 < 0 || grid[x][y-1] == '#') &&
            (y+2 < M && grid[x][y+1] == '.' && grid[x][y+2] == '.'))
           ||
           ((x-1 < 0 || grid[x-1][y] == '#') &&
            (x+2 < N && grid[x+1][y] == '.' && grid[x+2][y] == '.'))
       );

}

int main() {
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> grid[i][j];
    set<pii> clues;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (isClue(i, j, grid, N, M)) clues.insert({i, j});

    cout << clues.size() << endl;
    for (auto pair : clues) {
        cout << pair.first+1 << " " << pair.second+1 << endl;
    }

    return 0;
}