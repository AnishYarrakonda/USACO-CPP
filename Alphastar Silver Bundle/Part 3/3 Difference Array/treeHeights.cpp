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
    int N, I, H, R;
    cin >> N >> I >> H >> R;

    vi diffArr(N+1, 0);

    rep(i,0,R) {
        int A, B;
        cin >> A >> B;
        if (A > B) {
            int temp = A;
            A = B;
            B = temp;
        }
        A--; B--;

        diffArr[A+1]--;
        diffArr[B]++;
    }

    vi heights(N+1);

    int curr = H;
    rep(i,0,N+1) {
        heights[i] = curr;
        curr += diffArr[i];
    }

    rep(i,1,N+1) {
        cout << heights[i] << '\n';
    }
    
    return 0;
}