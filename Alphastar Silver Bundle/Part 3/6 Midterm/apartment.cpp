#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N; // M columns, N rows

    vector<vector<int>> a(N, vector<int>(M));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> a[r][c];
        }
    }

    // bit walls: 1=W, 2=N, 4=E, 8=S
    const int dr[4] = {0, -1, 0, 1};
    const int dc[4] = {-1, 0, 1, 0};
    const int bit[4] = {1, 2, 4, 8};

    vector<vector<int>> comp(N, vector<int>(M, -1));
    vector<int> sz;

    int rooms = 0;
    int largest = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (comp[r][c] != -1) continue;

            queue<pair<int, int>> q;
            q.push({r, c});
            comp[r][c] = rooms;
            int curSize = 0;

            while (!q.empty()) {
                auto [cr, cc] = q.front();
                q.pop();
                curSize++;

                for (int d = 0; d < 4; d++) {
                    if (a[cr][cc] & bit[d]) continue; // wall exists
                    int nr = cr + dr[d];
                    int nc = cc + dc[d];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if (comp[nr][nc] != -1) continue;
                    comp[nr][nc] = rooms;
                    q.push({nr, nc});
                }
            }

            sz.push_back(curSize);
            largest = max(largest, curSize);
            rooms++;
        }
    }

    int bestMerge = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int id1 = comp[r][c];
            // Only need to check east and south to avoid double counting.
            if (c + 1 < M) {
                int id2 = comp[r][c + 1];
                if (id1 != id2) bestMerge = max(bestMerge, sz[id1] + sz[id2]);
            }
            if (r + 1 < N) {
                int id2 = comp[r + 1][c];
                if (id1 != id2) bestMerge = max(bestMerge, sz[id1] + sz[id2]);
            }
        }
    }

    cout << rooms << "\n";
    cout << largest << "\n";
    cout << bestMerge << "\n";
    return 0;
}
