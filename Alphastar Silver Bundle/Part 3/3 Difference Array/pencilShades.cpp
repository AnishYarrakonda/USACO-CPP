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
    int N, K;
    cin >> N >> K;

    map<int,int> diffArray;
    diffArray.insert({0, 0});

    int curr = 0;
    while (N--) {
        int x;
        char c;
        cin >> x >> c;
        x *= c == 'R' ? 1 : -1;

        int pos = curr + x;

        diffArray.insert({pos, 0});

        diffArray[min(curr, pos)]++;
        diffArray[max(curr, pos)]--;

        curr = pos;
    }

    int running = 0;
    int prev = -1e9;
    int ANS = 0;
    for (auto [pos, change] : diffArray) {
        if (running >= K) {
            ANS += pos - prev;
        }
        running += change;
        prev = pos;
    }

    cout << ANS << endl;

    return 0;
}