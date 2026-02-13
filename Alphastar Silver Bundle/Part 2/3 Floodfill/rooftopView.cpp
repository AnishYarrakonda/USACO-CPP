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

int L, H;
int maxArea = 0;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

bool inBounds(int x, int y) {
    return (0 <= x && x < H && 0 <= y && y < L);
}

void floodfill(vv<char>& roof, vvi& visited) {
    rep(i,0,H) {
        rep(j,0,L) {
            if (roof[i][j] == '*' && !visited[i][j]) {
                queue<pi> q; q.push({i, j});
                visited[i][j] = 1;
                int total = 1;

                while (!q.empty()) {
                    auto [a, b]  = q.front(); q.pop();

                    rep(k, 0, 4) {
                        int x = a + dx[k];
                        int y = b + dy[k];
                        if (inBounds(x, y) && roof[x][y] == '*' && !visited[x][y]) {
                            q.push({x, y});
                            visited[x][y] = 1;
                            total += 1;
                        }
                    }
                }
                maxArea = max(maxArea, total);
            }
        }
    }
}

int main() {
    cin >> L >> H;
    vv<char> roof(H, v<char>(L));
    rep(i,0,H) rep(j,0,L) cin >> roof[i][j];
    vvi visited(H, vi(L, 0));

    floodfill(roof, visited);

    cout << maxArea << endl;

    return 0;
}