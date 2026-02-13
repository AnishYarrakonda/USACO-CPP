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

struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 20) ^ (size_t)p.second;
    }
};

int main() {
    int N; cin >> N;
    pi start; cin >> start.first >> start.second;
    unordered_set<pi, pair_hash> haybales;
    rep(i,0,N) {
        int x, y;
        cin >> x >> y;
        haybales.insert({x, y});
    }

    unordered_map<pi, int, pair_hash> broken; broken[start] = 0;
    queue<pi> q; q.push(start);

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        rep(k,0,4) {
            int a = x + dx[k];
            int b = y + dy[k];
            pi pos = {a,b};
            int cost = broken[{x, y}] + haybales.count(pos);

            if (0 <= a && a <= 1000 &&
                0 <= b && b <= 1000 &&
                (!broken.count(pos) || broken[pos] > cost)) {
                    broken[pos] = cost;
                    q.push(pos);
            }
        }
    }

    cout << broken[{0,0}] << endl;

    return 0;
}