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

int food;
int total = 0;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, -1, 1};

bool valid(int x) {
    return (0 <= x && x < 5);
}

void recurse(int a, int b, int x, int y, vvi grid, int eaten) {
    if (eaten == food) {
        total += a == x && b == y;
        return;
    }
    
    rep(i,0,16) {
        int newA = a + dx[i/4];
        int newB = b + dy[i/4];
        int newX = x + dx[i%4];
        int newY = y + dy[i%4];

        if (!valid(newA) || !valid(newB) ||
            !valid(newX) || !valid(newY)) continue;

        bool same = (newA == newX && newB == newY);

        int gain = same ? 1 : 2;
        if (same && eaten + 1 != food) continue;

        if (grid[newA][newB] && grid[newX][newY]) {
            vvi newGrid = grid;
            newGrid[newA][newB] = 0;
            newGrid[newX][newY] = 0;
            recurse(newA, newB, newX, newY, newGrid, eaten + gain);
        }
    }
}

int main() {
    vvi grid(5, vi(5, 1));
    int K; cin >> K;
    food = 25 - K;
    rep(i,0,K) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = 0;
    }

    grid[0][0] = 0;
    grid[4][4] = 0;
    recurse(0, 0, 4, 4, grid, 2);

    cout << total << endl;

    return 0;
}