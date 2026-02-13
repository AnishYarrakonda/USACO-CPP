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

// simple functions
template<typename T> bool ckmin(T &a, T b) { return b < a ? a=b, 1 : 0; }                   // update a to min of (a, b)
template<typename T> bool ckmax(T &a, T b) { return b > a ? a=b, 1 : 0; }                   // update a to max of (a, b)
template<typename T> T minv(const v<T>& vec) { return *min_element(all(vec)); }             // min of vector
template<typename T> T maxv(const v<T>& vec) { return *max_element(all(vec)); }             // max of vector
template<typename T> T sum(const v<T>& vec) { return accumulate(all(vec), T(0)); }          // sum of vector
template<typename T> int countv(const v<T>& vec, T val) { return count(all(vec), val); }    // count occurences

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }

// Solution Code below

int main() {
    int R, C; cin >> R >> C;
    vvi lake(R, vi(C));
    rep(i,0,R) rep(j,0,C) cin >> lake[i][j];

    vi dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vi dy = {1, 0, -1, 1, -1, 1, 0, -1};

    int maxDepth = 0;
    rep(i,0,R) {
        rep(j,0,C) {
            rep(k,0,8) {
                int x = i + dx[k];
                ckmax(x, 0); ckmin(x, R-1);
                int y = j + dy[k];
                ckmax(y, 0); ckmin(y, C-1);

                if (x == i && y == j) continue;

                if (lake[i][j] == lake[x][y]) {
                    ckmax(maxDepth, lake[i][j]);
                }
            }
        }
    }

    cout << maxDepth << endl;

    return 0;
}