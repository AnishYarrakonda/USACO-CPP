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

bool innocent(int x1, int y1, int t1, int x2, int y2, int t2) {
    ll dt = (ll)t1 - t2;
    ll dx = (ll)x1 - x2;
    ll dy = (ll)y1 - y2;
    return dt*dt < dx*dx + dy*dy;
}

int main() {
    int G, N;
    cin >> G >> N;

    v<p<int,pi>> grazings(G);
    rep(i,0,G) {
        int x, y, t;
        cin >> x >> y >> t;
        grazings[i] = {t, {x, y}};
    }
    sort(all(grazings));

    int ANS = 0;

    rep(i,0,N) {
        int x, y, t;
        cin >> x >> y >> t;
        p<int,pi> alibi = {t, {x, y}};

        auto spot = lower_bound(all(grazings), alibi);

        bool ok = false;

        if (spot != grazings.end()) {
            ok |= innocent(x,y,t,
                spot->second.first,
                spot->second.second,
                spot->first);
        }

        if (spot != grazings.begin()) {
            auto left = *(spot-1);
            ok |= innocent(x,y,t,
                left.second.first,
                left.second.second,
                left.first);
        }

        ANS += ok;
    }

    cout << ANS << endl;
    
    return 0;
}