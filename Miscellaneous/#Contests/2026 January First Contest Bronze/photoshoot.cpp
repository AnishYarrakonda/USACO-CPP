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
    int N, K; cin >> N >> K;
    int Q; cin >> Q;

    vvi grid(N, vi(N, 0));
    vv<ll> sums(N-K+1, v<ll>(N-K+1, 0));

    ll maxAttr = 0;
    rep(_,0,Q) {
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;

        int diff = v-grid[r][c];
        grid[r][c] = v;

        int startI = max(0, r - K + 1);
        int endI = min(r, N - K);
        int startJ = max(0, c - K + 1);
        int endJ = min(c, N - K);

        for (int i = startI; i <= endI; i++) {
            for (int j = startJ; j <= endJ; j++) {
                sums[i][j] += diff;
                maxAttr = max(sums[i][j], maxAttr);
            }
        }

        cout << maxAttr << endl;
    }

    return 0;
}