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

// Solution Code below
int main() {
    int W, R;
    cin >> W >> R;
    int mid = (W+1)/2;
    vector<tuple<int,int,int>> seats;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= W; c++) {
            int dist = (c-mid)*(c-mid) + (r-1)*(r-1);
            seats.push_back({dist, r, c});
        }
    }

    sort(seats.begin(), seats.end());

    vector<vector<int>> grid(R, vector<int>(W));

    for (int i = 0; i < R*W; i++) {
        int r = R - get<1>(seats[i]);
        int c = get<2>(seats[i]) - 1;
        grid[r][c] = i + 1;
    }

    prettyprint(grid);

    return 0;
}
