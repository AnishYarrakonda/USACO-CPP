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
    int T; cin >> T;

    rep(_,0,T) {
        // store answer
        ll ANS = 0;

        // read in input
        ll A, B, cA, cB, fA;
        cin >> A >> B >> cA >> cB >> fA;

        // calculate max A chips at the moment
        ll need = fA-A-(B/cB)*cA;
        
        // leftover B
        B %= cB;

        // if we already have what we needed without receiving additional chips
        if (need <= 0) {
            ANS = 0;
        }

        /*
        My greedy idea:
            - the ratio of the chips doesn't matter
            - you should always assume Bessie gets B chips over A chips
            - giving A chips directly makes no sense because
            - we have to group B chips in groups of cB before conversion
            - once we are one chip away from finshing the B chip groups
                - including the leftover B chips from before
            - switch over to A chips until we reach the remaining chips
            - needed that the B chip groups did not handle
        */

        // if we need more chips
        else {
            // essentially the same as ceil div without doubles
            ll fullExchanges = (need - 1) / cA;

            // remaining A chips
            ll remainingA = need - (fullExchanges * cA);

            // apply greedy strategy now
            
            // perform full exchanges
            // edge the last B group
            // then switch over to A
            ANS = (fullExchanges * cB) + (cB - 1) - B + remainingA;
        }

        // print out the answer
        cout << ANS << endl;
    }

    return 0;
}