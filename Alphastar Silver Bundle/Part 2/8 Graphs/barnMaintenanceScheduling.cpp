#include <bits/stdc++.h>
using namespace std;

// basic types
using ll = long long;
using db = double;
using str = string;

// generic templates
template<typename A, typename B> using p = pair<A,B>;
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using uset = unordered_set<T>;
template<typename K, typename V> using umap = unordered_map<K,V>;

using pi = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,a,b) for(int i = a; i < (b); i++)
#define all(x) (x).begin(),(x).end()

template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }
template<typename T> void prettyprintnewline(const v<T>& vec) { for(auto &x : vec) cout << x << '\n'; }

int main() {
    int N, M;
    cin >> N >> M;

    vvi adj(N);
    rep(i,0,M) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    // Read all blockers first
    vi blockers(N);
    rep(i,0,N) {
        cin >> blockers[i];
        blockers[i]--;
    }

    vi blocked(N, 0);

    rep(z,0,N) {
        int start = 0;
        while (start < N && blocked[start]) {
            start++;
        }

        if (start == N) {
            cout << "YES" << endl;
            continue;
        }

        vi visited(N, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int count = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                if (!visited[adjNode] && !blocked[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = 1;
                    count++;
                }
            }
        }

        cout << (count == N - z ? "YES" : "NO") << endl;
        
        blocked[blockers[z]] = 1;
    }
    
    return 0;
}