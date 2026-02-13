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

int dfs(int child, int parent, int K, int minR, vv<pi>& adj) {
    int total = 0;
    for (auto [adjNode, r] : adj[child]) {
        if (adjNode == parent) continue;
        if (min(r, minR) >= K) {
            total += dfs(adjNode, child, K, min(r, minR), adj);
            total++;
        }
    }
    return total;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vv<pi> adj(N+1);
    rep(i,0,N-1) {
        int p, q, r;
        cin >> p >> q >> r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    rep(i,0,Q) {
        int k, v;
        cin >> k >> v;
        cout << dfs(v, v, k, 1e9, adj) << endl;
    }

    return 0;
}