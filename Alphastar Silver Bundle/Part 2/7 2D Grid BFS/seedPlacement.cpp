#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
using vi = vector<int>;

#define rep(i,a,b) for(int i = a; i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<pi> seeds;
    map<pi,int> deg;
    queue<pi> q;

    int ANS = 0;

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    rep(_, 0, N) {
        int x, y;
        cin >> x >> y;
        pi coords = {x, y};

        if (seeds.count(coords)) {
            ANS--;
            cout << ANS << '\n';
            continue;
        }

        seeds.insert(coords);
        deg[coords] = 0;

        rep(k, 0, 4) {
            pi adj = {x + dx[k], y + dy[k]};
            if (seeds.count(adj)) {
                deg[coords]++;
                deg[adj]++;
                if (deg[adj] == 3) q.push(adj);
            }
        }

        if (deg[coords] == 3) q.push(coords);

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (deg[{a, b}] != 3) continue;

            rep(k, 0, 4) {
                pi nxt = {a + dx[k], b + dy[k]};
                if (!seeds.count(nxt)) {
                    seeds.insert(nxt);
                    deg[nxt] = 0;
                    ANS++;

                    rep(d, 0, 4) {
                        pi adj = {nxt.first + dx[d], nxt.second + dy[d]};
                        if (seeds.count(adj)) {
                            deg[nxt]++;
                            deg[adj]++;
                            if (deg[adj] == 3) q.push(adj);
                        }
                    }

                    if (deg[nxt] == 3) q.push(nxt);
                    break;
                }
            }
        }

        cout << ANS << '\n';
    }

    return 0;
}