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
    vi parity(N);
    int running = 0;
    rep(i,0,N) {
        int x;
        cin >> x;
        running = (running + x) % 7;
        parity[i] = running;
    }

    long ans = 0;
    rep(i,0,7) {
        auto it1 = find(all(parity), i);

        if (it1 == parity.end()) continue;

        auto rit = find(parity.rbegin(), parity.rend(), i);
        auto it2 = (++rit).base();

        ans = max(ans, it2-it1);
    }

    cout << ans << endl;

    return 0;
}