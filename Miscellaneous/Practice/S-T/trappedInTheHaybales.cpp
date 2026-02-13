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
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);

    int N; cin >> N;
    vector<pii> haybales(N);
    for (int i = 0; i < N; i++) {
        int S, P; cin >> S >> P;
        haybales[i] = {P, S};
    }
    sort(haybales.begin(), haybales.end());

    int area = 0;

    for (int i = 0; i < N-1; i++) {
        int l = i;
        int r = i+1;
        bool flag = false;
        
        while (l >= 0 && r < N) {
            int dist = haybales[r].first - haybales[l].first;
            if (dist > haybales[l].second) l--;
            else if (dist > haybales[r].second) r++;
            else {flag = true; break;}
        }

        if (flag) area += haybales[i+1].first - haybales[i].first;
    }

    cout << area << endl;

    return 0;
}