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

ll total = 0;

vi mergeVectors(vi arr1, vi arr2) {
    int i = 0, j = 0;
    vi result;
    
    while (i < arr1.size() && j < arr2.size()) {

        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            total += arr1.size() - i;
            j++;
        }    
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }
    
    return result;
}

vi mergeSort(vi arr) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;

    vi left(arr.begin(), arr.begin()+mid);
    vi right(arr.begin()+mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeVectors(left, right);
}



int main() {
    int N; cin >> N;
    vi IDs(N); rep(i,0,N) cin >> IDs[i];

    IDs = mergeSort(IDs);

    cout << total << endl;

    return 0;
}