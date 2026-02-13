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
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);

    int N; cin >> N;
    
    ll countC = 0;
    ll countCO = 0;
    ll countCOW = 0;

    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == 'C') countC++;
        else if (c == 'O') countCO += countC;
        else countCOW += countCO;
    }

    cout << countCOW << endl;

    return 0;
}