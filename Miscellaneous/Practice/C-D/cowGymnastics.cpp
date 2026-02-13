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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N; cin >> K >> N;
    vector<vint> practices(K, vint(N));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> practices[i][j];
        }
    }

    int total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            bool a = false; bool b = false;
            for (int k = 0; k < K; k++) {
                auto it1 = find(practices[k].begin(), practices[k].end(), i);
                auto it2 = find(practices[k].begin(), practices[k].end(), j);
                if (it1 < it2) a = true;
                else b = true;
            }
            total += a != b;
        }
    }

    cout << total << endl;

    return 0;
}