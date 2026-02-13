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
    vi A(N); rep(i,0,N) cin >> A[i];
    vi B(N); rep(i,0,N) cin >> B[i];
    vi adj(N+1); rep(i,0,N) adj[B[i]] = A[i];
    vi visited(N+1, 0);

    multiset<int> cycles;
    rep(i,1,N+1) {
        if (visited[i]) continue;

        int total = 0;
        visited[i] = 1;
        int currNode = i;
        bool b = false;

        while (true) {
            if (currNode == i && b) {
                break;
            }

            visited[currNode] = 1;
            currNode = adj[currNode];
            total++;
            b = true;
        }

        cycles.insert(total);
    }

    cycles.erase(1);

    if (cycles.size() == 0) {
        cout << "0" << " " << -1;
    } else {
        cout << cycles.size() << " ";
        cout << *max_element(all(cycles)) << endl;
    }

    return 0;
}