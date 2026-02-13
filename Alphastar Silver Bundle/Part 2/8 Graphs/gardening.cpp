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


void dfs(int child, int parent, vvi& adj, vi& seeds) {
    int i = 1;
    for (auto adjNode : adj[child]) {
        while (i == seeds[child] || i == seeds[parent]) i++;
        if (adjNode == parent) continue;
        seeds[adjNode] = i;
        dfs(adjNode, child, adj, seeds);
        i++;
    }
}

int main() {
    int N;
    cin >> N;

    vvi adj(N+1);
    rep(i,0,N-1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi seeds(N+1, 0);
    seeds[1] = 1;

    dfs(1, 1, adj, seeds);

    cout << *max_element(all(seeds)) << endl;

    return 0;
}