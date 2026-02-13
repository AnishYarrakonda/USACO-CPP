#include <bits/stdc++.h>
using namespace std;

// basic types
using ll = long long;
using db = double;
using str = string;

// generic templates
template<typename A, typename B> using p = pair<A,B>;               // Pair
template<typename T> using v = vector<T>;                           // 1D vector
template<typename T> using vv = vector<vector<T>>;                  // 2D vector
template<typename T> using uset = unordered_set<T>;                 // unordered set
template<typename K, typename V> using umap = unordered_map<K,V>;   // unordered map

// even shorter shorthands for data types dealing with int
using pi = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

// macros
#define rep(i,a,b) for(int i = a; i < (b); i++)     // for loop
#define all(x) (x).begin(),(x).end()                // entire container

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }
template<typename T> void prettyprintnewline(const v<T>& vec) { for(auto &x : vec) cout << x << '\n'; }

// Solution Code below

int main() {
    int N, M;
    cin >> N >> M;

    vv<v<pi>> switches(N, vv<pi>(N));
    rep(i,0,M) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x-1][y-1].push_back({a-1, b-1});
    }

    vvi on(N, vi(N, 0));
    on[0][0] = 1;

    vvi used(N, vi(N, 0));

    for (auto [u, v] : switches[0][0]) on[u][v] = 1;
    used[0][0] = 1;

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    bool changed = true;

    while (changed) {
        changed = false;

        queue<pi> q;
        q.push({0, 0});

        vvi visited(N, vi(N, 0));
        visited[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            rep(i,0,4) {
                int a = x + dx[i];
                int b = y + dy[i];

                if (a >= N || a < 0 ||
                    b >= N || b < 0) continue;

                if (visited[a][b]) continue;

                if (!on[a][b]) continue;
                
                if (!used[a][b]) {
                    for (auto [c, d] : switches[a][b]) {
                        on[c][d] = 1;
                    }
                    used[a][b] = 1;
                    changed = true;
                }

                q.push({a, b});
                visited[a][b] = 1;
            }
        }
    }

    int total = 0;
    rep(i,0,N) rep(j,0,N) total += on[i][j];

    cout << total << endl;

    return 0;
}