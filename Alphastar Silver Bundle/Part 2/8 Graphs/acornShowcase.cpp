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

    v<pi> acorns(N);
    rep(i,0,N) {
        cin >> acorns[i].first;
        cin >> acorns[i].second;
    }

    vvi adj(N);
    rep(i,0,M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi visited(N, 0);
    vv<pi> groups;
    queue<int> q;

    rep(i,0,N) {
        if (!visited[i]) {
            groups.push_back({acorns[i]});
            q.push(i);
            visited[i] = 1;
        } else {
            continue;
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = 1;
                    groups.back().push_back(acorns[adjNode]);
                }
            }
        }
    }

    int minPerimeter = 1e9;

    for (const auto& group : groups) {
        int maxX = 0; int maxY = 0;
        int minX = 1e9; int minY = 1e9;
        int i = 0;
        for (auto [x, y] : group) {
            if (i == 0) {
                minX = x;
                maxX = x;
                minY = y;
                maxY = y;
            }
            minX = min(x, minX);
            maxX = max(x, maxX);
            minY = min(y, minY);
            maxY = max(y, maxY);
            i++;
        }

        int perimeter = 2*(maxX-minX+maxY-minY);
        minPerimeter = min(perimeter, minPerimeter);
    }

    cout << minPerimeter << endl;
    

    return 0;
}