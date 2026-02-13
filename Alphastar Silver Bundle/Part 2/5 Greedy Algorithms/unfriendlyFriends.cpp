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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // Each interval is (right, left)
    v<pi> intervals;
    intervals.reserve(K);

    rep(i,0,K) {
        int u, v;
        cin >> u >> v;

        int l = min(u, v);
        int r = max(u, v) - 1;   // must cut somewhere in [l, r]

        intervals.push_back({r, l});
    }

    // Sort by earliest right endpoint
    sort(all(intervals));

    int last_cut = -1;
    int cuts = 0;

    for (auto [r, l] : intervals) {
        if (last_cut < l) {
            cuts++;
            last_cut = r;
        }
    }

    // Number of photos = number of cuts + 1
    int ANS = cuts + 1;
    cout << ANS << "\n";

    return 0;
}
