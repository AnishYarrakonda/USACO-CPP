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
    int M, N, M1, M2;
    cin >> M >> N >> M1 >> M2;

    vvi grid(M, vi(N));
    vvi dist(M, vi(N, 0));
    queue<pi> q;
    pi end;

    rep(i,0,M) rep(j,0,N) {
        cin >> grid[i][j];
        if (grid[i][j] == 3) {
            q.push({i,j});
        } else if (grid[i][j] == 4) {
            end = {i,j};
        }
    }

    vi dx = {M1, M1, -M1, -M1, M2, M2, -M2, -M2};
    vi dy = {M2, -M2, -M2, M2, M1, -M1, -M1, M1};

    while (!dist[end.first][end.second]) {
        auto [x, y] = q.front();
        q.pop();

        rep(i,0,8) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (0 <= a && a < M &&
                0 <= b && b < N &&
                grid[a][b] % 3 == 1 && !dist[a][b]) {
                    q.push({a,b});
                    dist[a][b] = dist[x][y] + 1;
            }
        }
    }

    cout << dist[end.first][end.second] << endl;

    return 0;
}