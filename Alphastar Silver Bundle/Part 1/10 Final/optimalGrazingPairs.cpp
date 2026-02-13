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
    int N; cin >> N;
    v<pi> freq;
    rep(i,0,N) {
        int x, y;
        cin >> x >> y;
        freq.push_back({y, x});
    }
    sort(all(freq));

    int grazingTime = 0;
    int i = 0, j = N - 1;

    while (i <= j) {
        if (i == j) {
            grazingTime = max(grazingTime, 2 * freq[i].first);
            break;
        }

        int time1 = freq[i].first;
        int time2 = freq[j].first;

        grazingTime = max(grazingTime, time1 + time2);

        int take = min(freq[i].second, freq[j].second);
        freq[i].second -= take;
        freq[j].second -= take;

        if (freq[i].second == 0) i++;
        if (freq[j].second == 0) j--;
    }



    cout << grazingTime << endl;

    return 0;
}