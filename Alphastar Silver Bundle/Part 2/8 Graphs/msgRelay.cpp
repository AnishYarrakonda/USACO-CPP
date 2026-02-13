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
    v<p<pi,int>> cows(N);
    rep(i,0,N) {
        cin >> cows[i].first.first;
        cin >> cows[i].first.second;
        cin >> cows[i].second;
    }

    vvi adj(N);

    rep(i,0,N) {
        rep(j,0,N) {
            if (i == j) continue;
            int dx = cows[i].first.first - cows[j].first.first;
            int dy = cows[i].first.second - cows[j].first.second;
            int dist = dx*dx + dy*dy;
            if (dist <= cows[i].second * cows[i].second) {
                adj[i].push_back(j);
            }
        }
    }


    int ANS = 0;

    
    queue<int> q;

    rep(i,0,N) {
        vi visited(N, 0); visited[i] = 1;
        int total = 1;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = 1;
                    total += 1;
                }
            }
        }
        ANS = max(ANS, total);
    }

    cout << ANS << endl;

    return 0;
}