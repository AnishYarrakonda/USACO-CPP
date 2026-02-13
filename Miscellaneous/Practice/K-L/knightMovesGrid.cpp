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

int N;

vi dx = {2, 2, 1, 1, -1, -1, -2, -2};
vi dy = {1, -1, 2, -2, 2, -2, 1, -1};

void bfs(int x, int y, vvi& grid) {
    queue<p<pi, int>> q;
    q.push({{0, 0}, 0});

    while (!q.empty()) {
        auto [pos, moves] = q.front();
        auto [x, y] = pos;
        q.pop();

        grid[x][y] = moves;

        rep(i,0,8) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (0 <= a && a < N  &&
                0 <= b && b < N  &&
                grid[a][b] == -1) {
                q.push({{a, b}, moves+1});
           }
        }
    }
}

int main() {
    cin >> N;
    vvi grid(N, vi(N, -1));

    bfs(0, 0, grid);

    prettyprint(grid);

    return 0;
}