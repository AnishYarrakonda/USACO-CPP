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
    int N, G;
    cin >> N >> G;

    vector<vector<int>> groups(G);

    vector<vector<int>> memberToGroups(N + 1);

    for (int g = 0; g < G; g++) {
        int S;
        cin >> S;
        groups[g].resize(S);
        for (int i = 0; i < S; i++) {
            cin >> groups[g][i];
            memberToGroups[groups[g][i]].push_back(g);
        }
    }
    
    vi counts(G, 0);
    uset<int> invited;

    queue<int> q;
    q.push(1);
    invited.insert(1);

    while (!q.empty()) {
        int newGuest = q.front();
        q.pop();

        for (int g : memberToGroups[newGuest]) {
            counts[g]++;

            if (counts[g] == groups[g].size()-1) {
                for (auto person : groups[g]) {
                    if (!invited.count(person)) {
                        invited.insert(person);
                        q.push(person);
                        break;
                    }
                }
            }
        }
    }

    cout << invited.size() << endl;

    return 0;
}