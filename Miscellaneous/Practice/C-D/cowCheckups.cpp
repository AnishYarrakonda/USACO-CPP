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

int N;
int original;

void reverse(int l, int r, vi& A, vi& B, vi& ans) {
    int correct = original;
    while (0 <= l && r < N) {
        correct -= A[l] == B[l];
        correct -= A[r] == B[r];
        correct += A[l] == B[r];
        correct += A[r] == B[l];
        ans[correct] += 1;
        l--;
        r++;
    }
}

int main() {
    cin >> N;
    vi A(N); rep(i,0,N) cin >> A[i];
    vi B(N); rep(i,0,N) cin >> B[i];
    
    rep(i,0,N) original += A[i] == B[i];

    vi ans(N+1, 0);

    rep(i,0,N-1) {
        reverse(i, i, A, B, ans);
        reverse(i, i+1, A, B, ans);
    }
    reverse(N-1, N-1, A, B, ans);

    prettyprintnewline(ans);

    return 0;
}