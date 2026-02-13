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
    int N;
    cin >> N;

    v<pi> adj(N);
    vi inDeg(N, 0);
    uset<int> nodes;
    ll total = 0;
    rep(i,0,N) {
        int p, a;
        cin >> p >> a;
        adj[i] = {p-1, a};
        inDeg[p-1]++;
        nodes.insert(i);
        total += a;
    }

    bool removed = true;
    while (removed) {
        removed = false;
        rep(i,0,N) {
            if (inDeg[i] == 0) {
                inDeg[i] = -1;
                nodes.erase(i);
                inDeg[adj[i].first]--;
                removed = true;
            }
        }
    }

    vi visited(N, 0);
    ll bad = 0;
    for (auto node : nodes) {
        if (visited[node]) continue;

        int currNode = node;
        vi cycle;

        while (true) {
            if (visited[currNode]) break;

            cycle.push_back(adj[currNode].second);
            visited[currNode] = 1;
            currNode = adj[currNode].first;
        }
        bad += *min_element(all(cycle));
    }

    cout << total - bad << endl;

    return 0;
}