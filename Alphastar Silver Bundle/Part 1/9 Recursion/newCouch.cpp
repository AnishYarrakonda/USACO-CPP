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

bool valid(vi& numbers) {
    rep(i,1,10) {
        int total = 0;
        int div = pow(10, i-1);
        for (auto number : numbers) {
            total += number / div % 10;
        }
        if (total >= 10) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vi numbers(N); rep(i,0,N) cin >> numbers[i];

    int maxSitting = 0;
    rep(i,1,pow(2,N)) {
        vi newNums;
        rep(j,0,N) if (i >> j & 1) newNums.push_back(numbers[j]);

        if (valid(newNums) && newNums.size() > maxSitting) maxSitting = newNums.size();
    }

    cout << maxSitting << endl;

    return 0;
}