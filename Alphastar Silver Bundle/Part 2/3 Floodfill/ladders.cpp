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

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

bool inBounds(int x, int y) {
    return (0 <= x && x < 2*N && 0 <= y && y < 2*N);
}

int region = -1;

void floodfill(vvi& grid, vvi& visited) {
    rep(i,0,2*N) {
        rep(j,0,2*N) {
            if (!(grid[i][j] || visited[i][j])) {
                queue<pi> q; q.push({i, j});
                visited[i][j] = 1;
                region++;

                while (!q.empty()) {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();

                    rep(k,0,4) {
                        int x = a + dx[k];
                        int y = b + dy[k];

                        if (inBounds(x, y) && !(grid[x][y] || visited[x][y])) {
                            visited[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;
    string moves; cin >> moves;

    vvi grid(2*N, vi(2*N, 0));
    vvi visited(2*N, vi(2*N, 0));

    unordered_map<char,pi> dxy = {
        {'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}
    };

    int x = N;
    int y = N;
    for (char dir : moves) {
        auto move = dxy[dir];
        rep(i,0,2) {
            x += move.first;
            y += move.second;
            grid[x][y] = 1;
        }
    }

    floodfill(grid, visited);

    cout << region << endl;

    return 0;
}