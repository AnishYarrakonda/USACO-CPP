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

    v<pi> moves(K);
    rep(i,0,K) {
        int a, b;
        cin >> a >> b;
        moves[i] = {a-1,b-1};
    }

    vi nums(N); rep(i,0,N) nums[i] = i;

    v<uset<int>> places(N);

    rep(i,0,N) {
        places[i].insert(i);
    }

    for (auto [a, b] : moves) {
        int dishA = nums[a];
        int dishB = nums[b];

        swap(nums[a], nums[b]);

        places[dishA].insert(b);
        places[dishB].insert(a);

    }

    vi cycleLengths(N);

    vi visited(N, 0);

    rep(i,0,N) {
        if (visited[i]) continue;

        vi cycle;
        int currNode = i;

        while (true) {
            if (visited[currNode]) break;

            cycle.push_back(currNode);
            visited[currNode] = 1;
            currNode = nums[currNode];
        }
        uset<int> bigSet;
        for (int x : cycle) {
            auto thing = places[x];
            bigSet.insert(all(thing));
        }

        int s = bigSet.size();

        for (int x : cycle) {
            cycleLengths[x] = s;
        }
    }
    
    prettyprintnewline(cycleLengths);

    return 0;
}