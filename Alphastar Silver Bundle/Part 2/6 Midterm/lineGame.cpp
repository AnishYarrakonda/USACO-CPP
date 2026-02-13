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
    int N;
    cin >> N;
    vi amounts(N);
    rep(i,0,N) cin >> amounts[i];

    int totalDist = 0;

    int balance = 0;
    int i = 0;
    set<int, greater<int>> owes;

    while (i < N) {
        if (amounts[i]) {
            if (amounts[i] > 0) {
                balance += amounts[i];
                amounts[i] = 0;
            } else {
                if (balance >= -amounts[i]) {
                    balance += amounts[i];
                    amounts[i] = 0;
                } else {
                    owes.insert(i);
                }
            }

            if (!owes.empty() && balance >= -amounts[*owes.begin()]) {
                balance += amounts[*owes.begin()];
                amounts[*owes.begin()] = 0;
                totalDist += i - *owes.begin();
                i = *owes.begin();
                owes.erase(owes.begin());
            }
        }

        i++;
        totalDist++;
    }

    cout << totalDist << endl;

    return 0;
}