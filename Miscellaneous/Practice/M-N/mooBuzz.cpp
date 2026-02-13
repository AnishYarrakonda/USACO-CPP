#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);

    vint mod = {14, 1, 2, 4, 7, 8, 11, 13};
    int N; cin >> N;
    cout << (N-1) / 8 * 15 + mod[N % 8];
    return 0;
}