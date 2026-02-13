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

void jump(int x, int y, vector<vector<char>>& grid, int& count, int R, int C) {
    if (x == R-1 && y == C-1) {
        count++;
        return;
    }
    
    for (int i = x+1; i < R; i++) {
        for (int j = y+1; j < C; j++) {
            if (grid[x][y] != grid[i][j]) jump(i, j, grid, count, R, C);
        }
    }
}

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    int R, C; cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    jump(0, 0, grid, count, R, C);

    cout << count << endl;

    return 0;
}