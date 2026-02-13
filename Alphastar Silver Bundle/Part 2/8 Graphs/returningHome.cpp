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

int N, NS, H;
int ANS1;
vi ANS2;

void dfs(int node, vvi& adj, int end, int dist, vi path) {
    path.push_back(node);

    if (node == end) {
        ANS1 = dist;
        ANS2 = path;
    }

    for (int adjNode : adj[node]) {
        dfs(adjNode, adj, end, dist+1, path);
    }
}

int main() {    
    cin >> N >> NS >> H;

    vvi adj(N+1);

    rep(i,0,NS) {
        int x, b1, b2;
        cin >> x >> b1 >> b2;
        adj[x].push_back(b1);
        adj[x].push_back(b2);
    }

    dfs(1, adj, H, 1, {});

    cout << ANS1 << endl;
    prettyprintnewline(ANS2);

    return 0;
}