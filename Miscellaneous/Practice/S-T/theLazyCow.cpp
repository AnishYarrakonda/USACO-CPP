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

int N, K;

bool inBounds(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int reachGrass(int x, int y, vvi& prefix) {
    int total = 0;
    rep(i,x-K,x+K+1) {
        if (inBounds(i,y)) {
            int side = K-abs(x-i);
            int rowSum = prefix[i][min(N, y+side+1)] - prefix[i][max(0, y-side)];
            total += rowSum;
        }
    }
    return total;
}

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);


    cin >> N >> K;
    vvi grid(N, vi(N));
    rep(i,0,N) rep(j,0,N) cin >> grid[i][j];

    vvi prefix(N, vi(N+1, 0));
    rep(i,0,N) rep(j,0,N) prefix[i][j+1] = prefix[i][j] + grid[i][j];

    int ANS = 0;
    rep(i,0,N) rep(j,0,N) ANS = max(ANS, reachGrass(i,j,prefix));
    cout << ANS << endl;

    return 0;
}