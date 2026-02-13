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

int N, M;
vi ans;

void recurse(vi& digits, int num, int depth, int idx) {
    if (depth == N) {
        ans.push_back(num);
        return;
    }
    rep(i, idx, M) {
        int newNum = num * 10 + digits[i];
        recurse(digits, newNum, depth + 1, i + 1);
    }
}

int main() {
    cin >> M;
    vi digits(M); rep(i,0,M) cin >> digits[i];
    cin >> N;

    recurse(digits, 0, 0, 0);

    prettyprintnewline(ans);

    return 0;
}