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

char recurse(int n, int k, vi& lengths) {
    if (k == 0) {
        return (n == 1 ? 'm' : 'o');
    }

    int leftLen = lengths[k - 1];
    int midLen = k + 3;

    if (n <= leftLen) {
        return recurse(n, k - 1, lengths);
    }
    else if (n <= leftLen + midLen) {
        return (n == leftLen + 1 ? 'm' : 'o');
    }
    else {
        return recurse(n - leftLen - midLen, k - 1, lengths);
    }
}

int main() {
    int N; cin >> N;

    int k = 0;
    vi lengths = {3};
    while (N > lengths.back()) {
        k += 1;
        lengths.push_back(2 * lengths.back() + k + 3);
    }

    cout << recurse(N, k, lengths) << endl;


    return 0;
}