#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<array<int, 2>> segments(N);
    vector<array<int, 2>> bessieSpeeds(M);

    int running = 0;
    for (int i = 0; i < N; i++) {
        int dist, speed;
        cin >> dist >> speed;
        segments[i] = {running, speed};
        running += dist;
    }

    running = 0;
    for (int i = 0; i < M; i++) {
        int dist, speed;
        cin >> dist >> speed;
        bessieSpeeds[i] = {running, speed};
        running += dist;
    }

    int worst = 0;
    for (int i = 0; i < 100; i++) {
        int j = 0;
        while (j + 1 < N && segments[j + 1][0] <= i) j++;
        int speedLimit = segments[j][1];

        j = 0;
        while (j + 1 < M && bessieSpeeds[j + 1][0] <= i) j++;
        int bessieSpeed = bessieSpeeds[j][1];

        worst = max(worst, bessieSpeed - speedLimit);
    }

    cout << worst << endl;
    return 0;
}