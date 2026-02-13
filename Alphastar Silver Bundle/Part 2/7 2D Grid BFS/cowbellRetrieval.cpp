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
    int R, C;
    cin >> R >> C;

    vv<char> grid(R, v<char>(C));
    vvi dist(R, vi(C, 0));
    queue<pi> q;
    pi end;

    rep(i,0,R) rep(j,0,C) {
        cin >> grid[i][j];
        if (grid[i][j] == 'B') {
            q.push({i,j});
        } else if (grid[i][j] == 'C') {
            end = {i, j};
        }
    }

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    while (!dist[end.first][end.second]) {
        auto [x, y] = q.front();
        q.pop();

        rep(i,0,4) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (0 <= a && a < R &&
                0 <= b && b < C &&
                grid[a][b] != '*' && !dist[a][b]) {
                    q.push({a,b});
                    dist[a][b] = dist[x][y] + 1;
            }
        }
    }

    cout << dist[end.first][end.second] << endl;

    return 0;
}