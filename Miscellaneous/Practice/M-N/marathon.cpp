#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

long long dist(int i, int j, vector<array<int, 2>>& checkpoints) {
    return llabs(checkpoints[i][0] - checkpoints[j][0]) +
           llabs(checkpoints[i][1] - checkpoints[j][1]);
}

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    
    int N;
    cin >> N;

    vector<array<int, 2>> checkpoints(N);
    for (int i = 0; i < N; i++) {
        cin >> checkpoints[i][0] >> checkpoints[i][1];
    }

    long long totalDist = 0;
    for (int i = 0; i < N - 1; i++) {
        totalDist += dist(i, i + 1, checkpoints);
    }

    long long leastDist = 1e18;
    for (int i = 1; i < N - 1; i++) {
        long long dist1 = dist(i, i - 1, checkpoints);
        long long dist2 = dist(i, i + 1, checkpoints);
        long long dist3 = dist(i - 1, i + 1, checkpoints);
        long long newDist = totalDist - dist1 - dist2 + dist3;
        leastDist = min(leastDist, newDist);
    }

    cout << leastDist << endl;
}
