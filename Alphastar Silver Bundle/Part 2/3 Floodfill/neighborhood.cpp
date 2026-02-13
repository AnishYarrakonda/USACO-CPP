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

int region = 1;
unordered_set<int> goodRegions;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

bool inBounds(int x, int y) {
    return (0 <= x && x < 100 && 0 <= y && y < 100);
}

void floodfill(vvi& grid, vvi& regions) {
    rep(i,0,100) {
        rep(j,0,100) {
            if (!regions[i][j]) {
                queue<pi> q;
                q.push({i, j});
                regions[i][j] = region;

                while (!q.empty()) {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();

                    rep(k,0,4) {
                        int x = a + dx[k];
                        int y = b + dy[k];

                        if (!inBounds(x, y)) {
                            goodRegions.insert(region);
                        } else if (!regions[x][y]) {
                            regions[x][y] = region;
                            q.push({x, y});
                        }
                    }
                }
                region++;
            }
        }
    }
}

int main() {
    vvi grid(100, vi(100, 0));
    vvi regions(100, vi(100, 0));
    int N; cin >> N;
    v<pi> containers(N);
    rep(i,0,N) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = 1;
        regions[x-1][y-1] = -1;
        containers[i] = {x-1, y-1};
    }

    floodfill(grid, regions);

    int perimeter = 0;

    for (auto [i, j] : containers) {
        rep(k,0,4) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (!inBounds(x, y) || goodRegions.count(regions[x][y])) {
                perimeter++;
            }
        }
    }

    cout << perimeter << endl;

    return 0;
}