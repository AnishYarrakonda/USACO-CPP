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
    int N, K, M;
    cin >> N >> K >> M;

    set<p<pi,pi>> fenced;
    rep(i,0,M) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        fenced.insert({{a, b}, {c, d}});
        fenced.insert({{c, d}, {a, b}});
    }

    v<pi> cows(K);
    rep(i,0,K) {
        cin >> cows[i].first; 
        cin >> cows[i].second;
        cows[i].first--;
        cows[i].second--;
    }

    vvi visited(N, vi(N, 0));
    int region = 1;

    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};

    rep(i,0,N) {
        rep(j,0,N) {
            if (visited[i][j]) continue;

            visited[i][j] = region;
            queue<pi> q;
            q.push({i, j});

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                rep(k,0,4) {
                    int a = x + dx[k];
                    int b = y + dy[k];

                    if (a < 0 || a >= N) continue;
                    if (b < 0 || b >= N) continue;
                    if (visited[a][b]) continue;
                    if (fenced.count({{x, y}, {a, b}})) continue;

                    visited[a][b] = region;
                    q.push({a, b});
                    
                }
            }
            region++;
        }
    }

    int separated = 0;
    for (auto [a, b] : cows) {
        for (auto [c, d] : cows) {
            separated += visited[a][b] != visited[c][d];
        }
    }

    cout << separated/2 << endl;

    return 0;
}