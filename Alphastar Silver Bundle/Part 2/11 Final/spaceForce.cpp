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

const int MAX = 301;
const int INF = 1e9;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool inBounds(int x, int y) {
    return x >= 0 && x < MAX && y >= 0 && y < MAX;
}

int main() {
    int A;
    cin >> A;

    vvi destroy(MAX, vi(MAX, INF));

    for (int i = 0; i < A; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        destroy[x][y] = min(destroy[x][y], t);
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inBounds(nx, ny)) {
                destroy[nx][ny] = min(destroy[nx][ny], t);
            }
        }
    }

    queue<tuple<int,int,int>> q;
    vv<bool> vis(MAX, v<bool>(MAX, false));

    q.push({0,0,0});
    vis[0][0] = true;

    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();

        if (destroy[x][y] == INF) {
            cout << t << "\n";
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int nt = t + 1;

            if (nx >= MAX || ny >= MAX) {
                cout << nt << "\n";
                return 0;
            }

            if (nx < 0 || ny < 0) continue;
            if (vis[nx][ny]) continue;
            if (nt >= destroy[nx][ny]) continue;

            vis[nx][ny] = true;
            q.push({nx, ny, nt});
        }
    }

    cout << -1 << "\n";
}