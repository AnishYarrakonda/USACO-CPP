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

int N, Tmax;

bool valid(int K, vi& D) {
    multiset<int> times;
    times.insert(D[0]);
    int i = 1;
    int time = 0;

    while (!times.empty()) {
        if (i >= K) {
            time = *times.begin();
            times.erase(times.begin());
        }

        if (i < N) {
            times.insert(D[i] + time);
        }

        i++;
    }

    return time <= Tmax;
}


int main() {
    cin >> N >> Tmax;
    vi D(N); rep(i,0,N) cin >> D[i];

    int ANS = 1e9;
    int low = 1, high = N;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (valid(mid, D)) {
            ANS = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    cout << ANS << endl;

    return 0;
}