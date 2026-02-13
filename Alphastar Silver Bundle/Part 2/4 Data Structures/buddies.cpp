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
    int C, N;
    cin >> C >> N;

    vector<int> seniors(C);
    for (int i = 0; i < C; i++) cin >> seniors[i];
    sort(seniors.begin(), seniors.end());

    vector<pi> freshmen(N);
    for (int i = 0; i < N; i++) {
        cin >> freshmen[i].first >> freshmen[i].second;
    }
    sort(freshmen.begin(), freshmen.end()); // by start time

    // min-heap by end time
    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;
    int j = 0;

    for (int time : seniors) {
        // add all freshmen who can start by this time
        while (j < N && freshmen[j].first <= time) {
            pq.push(freshmen[j].second);
            j++;
        }

        // remove freshmen who already expired
        while (!pq.empty() && pq.top() < time) {
            pq.pop();
        }

        // match if possible
        if (!pq.empty()) {
            pq.pop();
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
