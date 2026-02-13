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
    int N, M, Q;
    cin >> N >> M >> Q;

    vvi adj(N+1);
    rep(i,0,M) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi visited(N+1, 0);
    int region = 1;

    rep(i,1,N+1) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);
        visited[i] = region;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                if (visited[adjNode]) continue;

                visited[adjNode] = region;
                q.push(adjNode);
            }
        }
        region++;
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << (visited[u] == visited[v] ? 'Y' : 'N') << endl;
    }


    return 0;
}