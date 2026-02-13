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
    int T, _; cin >> T >> _;
    
    rep(_,0,T) {
        int N; cin >> N;
        string S; cin >> S;

        if (N % 2) {
            cout << -1 << endl;
            continue;
        }

        str frontHalf = S.substr(0, S.size()/2);
        str backHalf = S.substr(S.size()/2, S.size()/2);
        
        if (frontHalf == backHalf) {
            cout << 1 << endl;
            rep(i,0,S.size()-1) cout << 1 << " ";
            cout << 1 << endl;
            continue;
        }

        vi deletions(frontHalf.size()*2, 1);

        v<pi> options = {{0, 1}, {1, 2}, {0, 2}};
        for (int i = 0; i < frontHalf.size(); i += 3) {
            if (frontHalf[i] == backHalf[i] && frontHalf[i+1] == backHalf[i+1] && frontHalf[i+2] == backHalf[i+2]) { // CHANGE: Check all 3 chars match
                deletions[i] = 2;
                deletions[i+1] = 2;
                deletions[i+2] = 2;
                deletions[frontHalf.size()+i] = 2;
                deletions[frontHalf.size()+i+1] = 2;
                deletions[frontHalf.size()+i+2] = 2;
            } else {
                rep(j,0,9) {
                    auto [a, b] = options[j/3];
                    auto [c, d] = options[j%3];

                    if (frontHalf[i+a] == backHalf[i+c] && frontHalf[i+b] == backHalf[i+d]) {
                        deletions[i+a] = 2;
                        deletions[i+b] = 2;
                        int other1 = 3 - a - b;
                        deletions[i+other1] = 1;
                        
                        deletions[frontHalf.size()+i+c] = 2;
                        deletions[frontHalf.size()+i+d] = 2;

                        int other2 = 3 - c - d;
                        deletions[frontHalf.size()+i+other2] = 1;
                        break;
                    }
                }
            }
        }

        cout << 2 << endl;
        rep(i,0,deletions.size()) {
            cout << deletions[i];
            if (i < deletions.size()-1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}