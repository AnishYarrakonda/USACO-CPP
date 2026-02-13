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

vector<pii> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isPCL(int N, int x1, int y1, int x2, int y2, const vector<vector<char>>& grid) {
    map<char,int> colorToRegions; vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
             if (visited[i][j]) continue;
             colorToRegions.insert({grid[i][j], 0});
             colorToRegions[grid[i][j]] += 1;
             if (colorToRegions.size() > 2) return false;
             int counter = 0;
             for (const auto& pair : colorToRegions) counter += pair.second > 1;
             if (counter > 1) return false;

             queue<pii> q; q.push({i, j});
             visited[i][j] = true;

             while (!q.empty()) {
                int x = q.front().first; int y = q.front().second; q.pop();
                for (const auto& d : dxy) {
                    int dx = d.first; int dy = d.second;
                    int adjX = x + dx; int adjY = y + dy;
                    if (x1 <= adjX && adjX <= x2
                        && y1 <= adjY && adjY <= y2
                        && grid[adjX][adjY] == grid[x][y]
                        && !visited[adjX][adjY]) {
                            q.push({adjX, adjY});
                            visited[adjX][adjY] = true;
                    }
                }
             }
        }
    }
    bool hasContiguous = false; bool hasComponents = false;
    for (const auto& pair : colorToRegions) {
        if (pair.second > 1) hasComponents = true;
        else hasContiguous = true;
    }
    return hasContiguous && hasComponents;
}


int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    int N; cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> grid[i][j];

    vector<vector<int>> pclCandidates;
    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < N; y1++) {
            for (int x2 = x1; x2 < N; x2++) {
                for (int y2 = y1; y2 < N; y2++) {
                    if (isPCL(N, x1, y1, x2, y2, grid)) {
                        pclCandidates.push_back({x1, y1, x2, y2});
                    }
                }
            }
        }
    }

    int truePCLcount = 0;
    for (const auto& cand1 : pclCandidates) {
        bool maximal = true;
        for (const auto& cand2 : pclCandidates) {
            if (cand1 == cand2) continue;
            if (cand1[0] >= cand2[0] &&
                cand1[1] >= cand2[1] &&
                cand1[2] <= cand2[2] &&
                cand1[3] <= cand2[3]) {
                maximal = false;
                break;
            }
        }
        if (maximal) truePCLcount++;
    }

    cout << truePCLcount << endl;

    return 0;
}