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
    int N, M, K;
    cin >> N >> M >> K;

    v<pi> moves(M);
    rep(i,0,M) cin >> moves[i].first >> moves[i].second;

    vi acorns(N+1);
    rep(i,1,N+1) acorns[i] = i;

    for (auto [l, r] : moves) {
        reverse(acorns.begin()+l, acorns.begin()+r+1);
    }

    vi points(N+1);
    rep(i,1,N+1) {
        points[acorns[i]] = i;
    }

    vvi cycles;

    vi visited(N+1, 0);
    rep(i,1,N+1) {
        if (visited[i]) continue;

        vi cycle;
        int currNode = i;

        while (true) {
            if (visited[currNode]) break;

            cycle.push_back(currNode);
            visited[currNode] = 1;
            currNode = points[currNode];
        }
        cycles.push_back(cycle);
    }

    vi finalPos(N);
    for (const auto& cycle : cycles) {
        int sim = K % cycle.size();
        rep(i,0,cycle.size()) {
            finalPos[cycle[i]-1] = cycle[(i-sim+cycle.size())%cycle.size()];
        }
    }

    prettyprintnewline(finalPos);

    return 0;
}