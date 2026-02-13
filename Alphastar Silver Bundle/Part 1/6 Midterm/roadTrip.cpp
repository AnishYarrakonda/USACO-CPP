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

// simple functions
template<typename T> bool ckmin(T &a, T b) { return b < a ? a=b, 1 : 0; }                   // update a to min of (a, b)
template<typename T> bool ckmax(T &a, T b) { return b > a ? a=b, 1 : 0; }                   // update a to max of (a, b)
template<typename T> T minv(const v<T>& vec) { return *min_element(all(vec)); }             // min of vector
template<typename T> T maxv(const v<T>& vec) { return *max_element(all(vec)); }             // max of vector
template<typename T> T sum(const v<T>& vec) { return accumulate(all(vec), T(0)); }          // sum of vector
template<typename T> int countv(const v<T>& vec, T val) { return count(all(vec), val); }    // count occurences

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }

// Solution Code below
int main() {
    int N, M; cin >> N >> M;

    v<pi> actions1(N);
    rep(i,0,N) {
        int units; char dir;
        cin >> units >> dir;
        actions1[i] = {units, dir == 'R' ? 1 : -1};
    }

    v<pi> actions2(M);
    rep(i,0,M) {
        int units; char dir;
        cin >> units >> dir;
        actions2[i] = {units, dir == 'R' ? 1 : -1};
    }

    set<int> importantTimes;

    int running = 0;
    rep(i,0,N) {
        running += actions1[i].first;
        importantTimes.insert(running);
    }

    running = 0;
    rep(i,0,M) {
        running += actions2[i].first;
        importantTimes.insert(running);
    }

    vi inequalities;
    int cow1 = 0, cow2 = 0;
    int i = 0, j = 0;
    int currTime = 0;
    bool still1 = false, still2 = false;
    for (auto time : importantTimes) {
        int timeToSim = time - currTime;

        if (!still1) {
            cow1 += actions1[i].second * timeToSim;
            actions1[i].first -= timeToSim;
            if (!actions1[i].first) {
                if (i == N-1) still1 = true;
                else i++;
            }
        }

        if (!still2) {
            cow2 += actions2[j].second * timeToSim;
            actions2[j].first -= timeToSim;
            if (!actions2[j].first) {
                if (j == M-1) still2 = true;
                else j++;
            }
        }

        int sign;
        if (cow1 > cow2) sign = 1;
        else if (cow1 < cow2) sign = 2;
        else sign = 3;

        inequalities.push_back(sign);
        currTime = time;
    }

    int ans = 0;
    int prev = inequalities[0];
    rep(i,1,inequalities.size()) {
        int curr = inequalities[i];
        if (prev != curr && prev != 3) ans += 1;
        prev = curr;
    }

    cout << ans << endl;

    return 0;
}