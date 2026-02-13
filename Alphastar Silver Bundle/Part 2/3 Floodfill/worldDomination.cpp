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

bool inBounds(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

pi bestContinent = {0, -1e9};

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

void floodfill(vvi& grid, vvi& visited) {
    rep(i,0,N) {
        rep(j,0,N) {
            if (grid[i][j] && !visited[i][j]) {
                queue<pi> q;
                q.push({i, j});
                visited[i][j] = 1;

                int area = 0;
                int perimeter = 0;

                while (!q.empty()) {
                    auto [a, b] = q.front();
                    q.pop();

                    area++;
                    
                    rep(k,0,4) {
                        int x = a + dx[k];
                        int y = b + dy[k];

                        if (inBounds(x, y) && grid[x][y]) {
                            if (!visited[x][y]) {
                                q.push({x, y});
                                visited[x][y] = 1;
                            }
                        } else {
                            perimeter++;
                        }
                    }
                }
                pi continent = make_pair(area, -perimeter);
                if (continent > bestContinent) {
                    bestContinent = continent;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    vvi grid(N, vi(N, 0));
    rep(i,0,N) {
        rep(j,0,N) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
            }
        }
    }
    vvi visited(N, vi(N, 0));

    floodfill(grid, visited);

    cout << bestContinent.first << " " << -bestContinent.second << endl;

    return 0;
}