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

int recurse(int cow, v<pi>& cows, vi& donuts) {
    if (!donuts[cows[cow].first]) {
        donuts[cows[cow].first] = cow;
        return 1;
    } 
    else if (donuts[cows[cow].first] > cow) {
        int temp = donuts[cows[cow].first];
        donuts[cows[cow].first] = cow;
        return recurse(temp, cows, donuts);
    }
    else if (!donuts[cows[cow].second]) {
        donuts[cows[cow].second] = cow;
        return 1;
    }
    else if (donuts[cows[cow].second] > cow) {
        int temp = donuts[cows[cow].second];
        donuts[cows[cow].second] = cow;
        return recurse(temp, cows, donuts);
    }

    return 0;
}

int main() {
    int N, M; cin >> N >> M;
    v<pi> cows(N+1); rep(i,1,N+1) cin >> cows[i].first >> cows[i].second;
    vi donuts(M+1, 0);

    int total = 0;
    stack<int> ans;
    for (int i = N; i > 0; i--) {
        total += recurse(i, cows, donuts);
        ans.push(total);
    }

    rep(i,0,N) {
        cout << ans.top() << "\n";
        ans.pop();
    }

    return 0;
}