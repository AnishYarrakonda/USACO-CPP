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
#define f first                                     // first in pair
#define s second                                    // second in pair

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
template<typename T> void prettylines(const v<T>& vec) { for(auto &x : vec) cout << x << '\n'; }

// Solution Code below

bool comp(const v<ll> &a, const v<ll> &b) {
    return a[0]*b[1] > a[1]*b[0];
}

int main() {
    ll F, M, N; cin >> F >> M >> N;
    vv<ll> parts(N);
    rep(i,0,N) {
        int f1, m1; cin >> f1 >> m1;
        v<ll> part = {f1, m1, i};
        parts[i] = part;
    }
    sort(all(parts), comp);

    v<ll> bestParts;
    rep(i,0,N) {
        ll F1 = parts[i][0];
        ll M1 = parts[i][1];
        if (F*(M+M1) < (F+F1)*M) {
            F += F1;
            M += M1;
            bestParts.push_back(parts[i][2]+1);
        } else break;
    }
    sort(all(bestParts));

    if (bestParts.empty()) cout << "NONE" << endl;
    else prettylines(bestParts);

    return 0;
}