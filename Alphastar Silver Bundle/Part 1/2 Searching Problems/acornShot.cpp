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

// simple functions
template<typename T> bool ckmin(T &a, T b) { return b < a ? a=b, 1 : 0; }                   // update a to min of (a, b)
template<typename T> bool ckmax(T &a, T b) { return b > a ? a=b, 1 : 0; }                   // update a to max of (a, b)
template<typename T> T minv(const v<T>& vec) { return *min_element(all(vec)); }             // min of vector
template<typename T> T maxv(const v<T>& vec) { return *max_element(all(vec)); }             // max of vector
template<typename T> T sum(const v<T>& vec) { return accumulate(all(vec), T(0)); }          // sum of vector
template<typename T> int countv(const v<T>& vec, T val) { return count(all(vec), val); }    // count occurences

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }

// Solution Code below
int N, K;

bool valid(int R, vi& X) {
    int shots = 0;
    int range = 2 * R;
    int pos = -1e9;
    rep(i,0,N) {
        if (X[i] - pos > range) {
            shots++;
            pos = X[i];
        }
    }
    return shots <= K;
}

int main() {
    cin >> N >> K;
    vi X(N); rep(i,0,N) cin >> X[i];
    sort(all(X));
    
    int ANS = 0;
    int left = 1, right = X.back()-X.front()+1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (valid(mid, X)) {
            right = mid;
            ANS = mid;
        } else {
            left = mid+1;
        }
    }


    cout << ANS << '\n';
    
    return 0;
}