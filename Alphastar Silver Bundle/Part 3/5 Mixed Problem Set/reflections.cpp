#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    auto idOf = [&](int r, int c, int dir) {
        return ((r * M + c) << 2) | dir;
    };

    int S = 4 * N * M;
    vector<int> nxt(S, -1), indeg(S, 0), head(S, -1);
    vector<int> to, nextEdge;
    to.reserve(S);
    nextEdge.reserve(S);

    auto addReverseEdge = [&](int u, int v) {
        // Edge u -> v in forward graph; store reverse on v.
        to.push_back(u);
        nextEdge.push_back(head[v]);
        head[v] = (int)to.size() - 1;
    };

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            for (int dir = 0; dir < 4; dir++) {
                int ndir;
                if (grid[r][c] == '/') {
                    if (dir == UP) ndir = RIGHT;
                    else if (dir == RIGHT) ndir = UP;
                    else if (dir == DOWN) ndir = LEFT;
                    else ndir = DOWN;
                } else {
                    if (dir == UP) ndir = LEFT;
                    else if (dir == LEFT) ndir = UP;
                    else if (dir == DOWN) ndir = RIGHT;
                    else ndir = DOWN;
                }

                int nr = r + dr[ndir];
                int nc = c + dc[ndir];

                int u = idOf(r, c, dir);
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    nxt[u] = -1;
                } else {
                    int v = idOf(nr, nc, ndir);
                    nxt[u] = v;
                    indeg[v]++;
                    addReverseEdge(u, v);
                }
            }
        }
    }

    // Find cycle nodes via indegree peeling.
    vector<char> removed(S, 0);
    queue<int> q;
    for (int i = 0; i < S; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        removed[u] = 1;

        int v = nxt[u];
        if (v != -1) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    vector<char> inf(S, 0);
    queue<int> qInf;

    for (int i = 0; i < S; i++) {
        if (!removed[i]) {
            inf[i] = 1; // cycle node
            qInf.push(i);
        }
    }

    // All predecessors of cycle nodes are also infinite.
    while (!qInf.empty()) {
        int u = qInf.front();
        qInf.pop();

        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            int p = to[e];
            if (!inf[p]) {
                inf[p] = 1;
                qInf.push(p);
            }
        }
    }

    // Compute finite lengths to exit: len[u] = bounces until exit from state u.
    vector<int> len(S, -1);
    queue<int> qLen;

    for (int i = 0; i < S; i++) {
        if (!inf[i] && nxt[i] == -1) {
            len[i] = 1;
            qLen.push(i);
        }
    }

    while (!qLen.empty()) {
        int u = qLen.front();
        qLen.pop();

        for (int e = head[u]; e != -1; e = nextEdge[e]) {
            int p = to[e];
            if (inf[p]) continue;
            if (len[p] == -1) {
                len[p] = len[u] + 1;
                qLen.push(p);
            }
        }
    }

    vector<int> entries;
    entries.reserve(2 * N + 2 * M);

    for (int c = 0; c < M; c++) entries.push_back(idOf(0, c, DOWN));
    for (int c = 0; c < M; c++) entries.push_back(idOf(N - 1, c, UP));
    for (int r = 0; r < N; r++) entries.push_back(idOf(r, 0, RIGHT));
    for (int r = 0; r < N; r++) entries.push_back(idOf(r, M - 1, LEFT));

    int best = 0;
    for (int s : entries) {
        if (inf[s]) {
            cout << -1 << "\n";
            return 0;
        }
        best = max(best, len[s]);
    }

    cout << best << "\n";
    return 0;
}
