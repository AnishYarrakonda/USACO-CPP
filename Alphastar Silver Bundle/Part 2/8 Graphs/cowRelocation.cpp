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
    int N; cin >> N;

    vvi adj(N);
    vi inDeg(N, 0);

    rep(u,0,N) {
        int v; cin >> v;
        adj[u].push_back(v-1);
        inDeg[v-1]++;
    }

    int count = 0;
    queue<int> q;
    
    rep(i,0,N) {
        if (inDeg[i] == 0) {
            q.push(i);
            count++;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int adjNode : adj[node]) {
            inDeg[adjNode]--;
            if (inDeg[adjNode] == 0) {
                q.push(adjNode);
                count++;
            }
        }
    }

    cout << N-count << endl;
    return 0;
}