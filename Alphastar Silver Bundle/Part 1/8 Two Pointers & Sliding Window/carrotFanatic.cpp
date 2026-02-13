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

int main() {
    int N, K; cin >> N >> K;
    vi carrots(N); rep(i,0,N) cin >> carrots[i];
    sort(all(carrots));

    int display1 = 0;
    int a, b;

    int i = 0, j = 0;
    while (i < N && j < N) {
        
        if (carrots[j] - carrots[i] <= K) {
        
            if (j-i+1 > display1) {
                display1 = j-i+1;
                a = i; b = j;
            }
        
            j++;
        } 
        
        else
            i++;
    }

    carrots.erase(carrots.begin()+a, carrots.begin()+b+1);

    int display2 = 0;

    i = 0; j = 0;
    while (i < carrots.size() && j < carrots.size()) {
        if (carrots[j] - carrots[i] <= K) {
            ckmax(display2, j-i+1);
            j++;
        } else i++;
    }

    cout << display1+display2 << endl;

    return 0;
}