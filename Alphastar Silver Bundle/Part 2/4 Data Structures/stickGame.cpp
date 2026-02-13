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

    v<pi> points;

    rep(i,0,N) {
        int x, y; cin >> x >> y;
        points.push_back({x,y});
    }

    rep(i,0,4) {
        v<pi> dupPoints(points);
        umap<int,int> freq;
        set<pi> used;
        int best = -1;
        freq[best] = -1;
        
        rep(j,0,i) {
            for (auto [x, y] : dupPoints) {
                if (used.count({x,y})) continue;

                freq.insert({x, 0});
                freq[x]++;
                if (freq[x] > freq[best]) best = x;
            }
            
            rep(a,0,N) {
                auto [x, y] = dupPoints[a];
                if (x == best) used.insert({x,y});
            }

            freq.clear();
            best = -1;
        }

        rep(j,0,3-i) {
            for (auto [x, y] : dupPoints) {
                if (used.count({x,y})) continue;

                freq.insert({y, 0});
                freq[y]++;
                if (freq[y] > freq[best]) best = y;
            }
            
            rep(a,0,N) {
                auto [x, y] = dupPoints[a];
                if (y == best) used.insert({x,y});
            }

            freq.clear();
            best = -1;
            freq[best] = -1;
        }

        if (used.size() == N) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}