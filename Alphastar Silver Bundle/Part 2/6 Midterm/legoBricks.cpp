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

int N, M;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void floodfill(vvi& grid, vvi& visited) {
    int group = 1;
    rep(i,0,N) {
        rep(j,0,M) {
            if (grid[i][j] && !visited[i][j]) {
                queue<pi> q;
                q.push({i,j});
                visited[i][j] = group;

                while (!q.empty()) {
                    auto [a, b] = q.front();
                    q.pop();

                    rep(k,0,4) {
                        int x = a + dx[k];
                        int y = b + dy[k];

                        if (0 <= x && x < N &&
                            0 <= y && y < M &&
                            grid[x][y] && !visited[x][y]) {
                                visited[x][y] = group;
                                q.push({x,y});
                        }
                    }
                }
                group++;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vvi grid(N, vi(M, 0));
    vvi visited(N, vi(M, 0));
    rep(i,0,N) {
        rep(j,0,M) {
            char c;
            cin >> c;
            grid[i][j] = c == 'X';
        }
    }

    floodfill(grid, visited);

    v<pi> group1, group2;

    rep(i,0,N) {
        rep(j,0,M) {
            if (grid[i][j]) {
                if (visited[i][j] == 1) {
                    group1.push_back({i,j});
                } else {
                    group2.push_back({i,j});
                }
            }
        }
    }

    int minDistance = 10000;

    for (auto [x1, y1] : group1) {
        for (auto [x2, y2] : group2) {
            int distX = abs(x1-x2);
            int distY = abs(y1-y2);
            minDistance = min(minDistance, distX+distY-1);
        }
    }

    cout << minDistance << endl;

    return 0;
}