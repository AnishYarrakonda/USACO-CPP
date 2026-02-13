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
    int N, M;
    cin >> N >> M;

    vv<pi> adj(N);

    rep(i,0,M) {
        char c;
        int u, v;
        cin >> c;
        cin >> u >> v;
        u--; v--;
        int w = c == 'S';
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vi visited(N, 0);
    bool impossible = false;
    int count = 0;

    rep(i,0,N) {
         if (visited[i]) continue;

         queue<int> q;
         q.push(i);
         visited[i] = 1;

         while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto [v, w] : adj[node]) {
                if (!visited[v]) {
                    if (w) {
                        visited[v] = visited[node];
                    } else {
                        visited[v] = visited[node] == 1 ? 2 : 1;
                    }
                    q.push(v);
                } else {
                    if (w && visited[node] != visited[v]) impossible = true;
                    if (!w && visited[node] == visited[v]) impossible = true;
                }
            }
         }
         count++;
    }

    if (impossible) cout << 0 << endl;
    else {
        cout << 1;
        rep(i,0,count) cout << 0;
    }

    return 0;
}