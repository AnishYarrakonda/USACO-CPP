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
int N, K;

bool valid(vi& X, int R) {
    int range = 2*R;
    int count = 0;
    
    int start = 0;
    rep(i,1,N) {
        if (X[i]-X[start] > 2*R) {
            start = i;
            count++;
        }
    }

    if (X.back() - X[start] < range) count++;

    return count <= K;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> N >> K;

    vi X(N);
    rep(i,0,N) cin >> X[i];
    sort(all(X));

    int ANS = -1;

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (valid(X, mid)) {
            ANS = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ANS << endl;
    
    return 0;
}