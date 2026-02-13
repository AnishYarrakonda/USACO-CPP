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
int ans = 0;

bool isValid(vi& candies, v<v<p<int,bool>>>& relationships) {
    rep(i,0,candies.size()) {
        for (auto relation : relationships[i]) {
            if (relation.first >= candies.size()) continue;
            if (!(candies[i] == candies[relation.first] == relation.second)) {
                return false;
            }
        }
    }
    return true;
}

void recurse(vi& candies, v<v<p<int,bool>>>& relationships) {
    if (candies.size() == N) {
        if (isValid(candies, relationships)) {
            ans++;
        }
    } else {
        vi x(candies); x.push_back(1); recurse(x, relationships);
        vi y(candies); y.push_back(2); recurse(y, relationships);
        vi z(candies); z.push_back(3); recurse(z, relationships);
    }
}

int main() {
    cin >> N >> K;
    v<v<p<int,bool>>> relationships(N);
    set<p<int,int>> seenPairs;
    rep(i,0,K) {
        char c; int x, y;
        cin >> c >> x >> y;
        bool b = c == 'S';
        if (!seenPairs.count({x,y})) {
            relationships[x-1].push_back({y-1, b});
            relationships[y-1].push_back({x-1, b});
            seenPairs.insert({x,y});
        }
    }

    vi thing;
    recurse(thing, relationships);

    cout << ans << endl;

    return 0;
}