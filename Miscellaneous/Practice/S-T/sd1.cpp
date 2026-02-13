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
#define f first                                     // first in pair
#define s second                                    // second in pair

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

int N;
string s;

bool can(int D) {
    int last = -1e9;
    int added = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            last = i;
        } else {
            if (i - last >= D) {
                added++;
                last = i;
                if (added == 2) return true;
            }
        }
    }
    return false;
}

int find_largest_interior_gap(string s, int &gap_start)
{
  int biggest_gap = 0, current_start = -1, N = s.length();
  for (int i=0; i<N; i++) 
    if (s[i] == '1') {
      if (current_start!=-1 && i-current_start > biggest_gap) {
	biggest_gap = i-current_start;
	gap_start = current_start;
      }
      current_start = i;
    }
  return biggest_gap;
}
 
// Returns size of smallest gap between two 1s
int find_smallest_interior_gap(string s)
{
  int smallest_gap = 1000000000, current_start = -1, N = s.length();
  for (int i=0; i<N; i++) 
    if (s[i] == '1') {
      if (current_start!=-1 && i-current_start < smallest_gap) smallest_gap = i-current_start;
      current_start = i;
    }
  return smallest_gap;
}
 
int try_cow_in_largest_gap(string s)
{
  int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
  if (largest_gap >= 2) {
    s[gap_start + largest_gap / 2] = '1';
    return find_smallest_interior_gap(s);
  } 
  return -1; // no gap!
}
 
int main(void)
{
  ifstream fin ("socdist1.in");
  int N;
  string s, temp_s;
  fin >> N >> s;
  ofstream fout ("socdist1.out");
  int answer = 0;
 
  // Possibility 1. put two cows in largest interior gap
  int gap_start, largest_gap = find_largest_interior_gap(s, gap_start);
  if (largest_gap >= 3) {
    temp_s = s;
    temp_s[gap_start + largest_gap / 3] = '1';
    temp_s[gap_start + largest_gap * 2 / 3] = '1';
    answer = max(answer, find_smallest_interior_gap(temp_s));
  }
 
  // Possibility 2. cows at both ends
  if (s[0] == '0' && s[N-1] == '0') {
    temp_s = s; temp_s[0] = temp_s[N-1] = '1';
    answer = max(answer, find_smallest_interior_gap(temp_s));        
  }
 
  // Possibility 3. cow at left + cow in largest interior gap
  if (s[0] == '0') {
    temp_s = s; temp_s[0] = '1';
    answer = max(answer, try_cow_in_largest_gap(temp_s));
  }
 
  // Possibility 4. cow at right + cow in largest interior gap
  if (s[N-1] == '0') {
    temp_s = s; temp_s[N-1] = '1';
    answer = max(answer, try_cow_in_largest_gap(temp_s));
  }
 
  // Possibility 5. cow at largest interior gap.  done twice.
  if (largest_gap >= 2) {
    temp_s = s; temp_s[gap_start + largest_gap / 2] = '1';
    answer = max(answer, try_cow_in_largest_gap(temp_s));
  }
 
  fout << answer << "\n";
  return 0;
}