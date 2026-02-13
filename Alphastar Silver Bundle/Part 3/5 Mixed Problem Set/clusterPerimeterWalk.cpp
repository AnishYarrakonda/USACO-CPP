#include <bits/stdc++.h>
using namespace std;

struct State {
    int r, c, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<string> g(R);
    for (int i = 0; i < R; i++) cin >> g[i];

    int sr = -1, sc = -1;
    int pr = -1, pc = -1; // reference point inside cluster

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (g[r][c] == '*') {
                sr = r;
                sc = c;
            }
            if (g[r][c] == 'X' && pr == -1) {
                pr = r;
                pc = c;
            }
        }
    }

    const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    auto inBounds = [&](int r, int c) {
        return (0 <= r && r < R && 0 <= c && c < C);
    };

    auto isBlocked = [&](int r, int c) {
        return g[r][c] == 'X';
    };

    // Winding delta for crossing the horizontal ray y = pr, x > pc.
    auto crossingDelta = [&](int r1, int c1, int r2, int c2) {
        if (r1 == r2) return 0;

        bool crosses = ((r1 <= pr && r2 > pr) || (r2 <= pr && r1 > pr));
        if (!crosses) return 0;

        double xInter = c1 + (double)(pr - r1) * (double)(c2 - c1) / (double)(r2 - r1);
        if (xInter <= (double)pc) return 0;

        // Directional contribution (sign choice is arbitrary, consistency matters).
        return (r2 > r1 ? 1 : -1);
    };

    int startIdx = sr * C + sc;
    vector<unordered_map<int, int>> dist(R * C);
    queue<State> q;

    dist[startIdx][0] = 0;
    q.push({sr, sc, 0});

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        int idx = cur.r * C + cur.c;
        int d = dist[idx][cur.w];

        for (int mv = 0; mv < 8; mv++) {
            int nr = cur.r + dr[mv];
            int nc = cur.c + dc[mv];
            if (!inBounds(nr, nc)) continue;
            if (isBlocked(nr, nc)) continue;

            // Prevent diagonal corner-cutting through trees.
            if (cur.r != nr && cur.c != nc) {
                int ar = cur.r, ac = nc;
                int br = nr, bc = cur.c;
                if (inBounds(ar, ac) && inBounds(br, bc) && isBlocked(ar, ac) && isBlocked(br, bc)) {
                    continue;
                }
            }

            int nw = cur.w + crossingDelta(cur.r, cur.c, nr, nc);
            int nidx = nr * C + nc;

            if (nidx == startIdx && nw != 0) {
                cout << d + 1 << "\n";
                return 0;
            }

            auto it = dist[nidx].find(nw);
            if (it == dist[nidx].end()) {
                dist[nidx][nw] = d + 1;
                q.push({nr, nc, nw});
            }
        }
    }

    // Should not happen with valid inputs.
    cout << -1 << "\n";
    return 0;
}
