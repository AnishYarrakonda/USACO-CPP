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
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N; cin >> N;

    vector<pii> allPoints(N);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        allPoints[i] = {x, y};
    }

    int maxArea = 0;
    for (auto [x1, y1] : allPoints) {
        for (auto [x2, y2] : allPoints) {
            for (auto [x3, y3] : allPoints) {
                if (x1 == x2 && y2 == y3) {
                    maxArea = max(maxArea, abs(x2-x3)*abs(y1-y2));
                }
            }
        }
    }

    cout << maxArea << '\n';

    return 0;
}