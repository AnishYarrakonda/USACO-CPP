#include <bits/stdc++.h>
using namespace std;

// basic types
using ll = long long;
using db = double;
using str = string;

// generic templates
template<typename A, typename B> using p = pair<A,B>;
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using uset = unordered_set<T>;
template<typename K, typename V> using umap = unordered_map<K,V>;

// even shorter shorthands for data types dealing with int
using pi = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

// macros
#define rep(i,a,b) for(int i = a; i < (b); i++)
#define all(x) (x).begin(),(x).end()

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { 
    for(auto &x : vec) cout << x << ' '; 
    cout << '\n'; 
}
template<typename T> void prettyprint(const vv<T>& mat) { 
    for(auto &row : mat) prettyprint(row); 
}
template<typename T> void prettyprintnewline(const v<T>& vec) { 
    for(auto &x : vec) cout << x << '\n'; 
}

// Solution Code below

void quicksort(vi& arr, int left, int right) {
    if (right - left <= 1) return;

    int pivot = arr[right-1];
    int next = left;
    
    // Partition: move all elements <= pivot to the left
    rep(i, left, right-1) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[next]);
            next += 1;
        }
    }
    
    // Place pivot in its correct position
    swap(arr[next], arr[right - 1]);
    
    // Print after complete partition
    prettyprint(arr);
    
    // Recursively sort left and right subarrays
    // Left part: [left, next) - elements < pivot
    // Right part: [next+1, right) - elements > pivot
    // Position 'next' contains the pivot, so we skip it
    quicksort(arr, left, next);
    quicksort(arr, next + 1, right);
}

int main() {
    int N; 
    cin >> N;
    vi arr(N); 
    rep(i, 0, N) cin >> arr[i];
    
    quicksort(arr, 0, N);

    return 0;
}