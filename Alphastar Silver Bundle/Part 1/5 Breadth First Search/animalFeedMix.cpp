#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, K, M;
    cin >> X >> Y >> K >> M;

    bool visited[101][101][101] = {};
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    visited[0][0][0] = true;

    int bestDiff = abs(M - 0);

    while (!q.empty()) {
        auto [a, b, steps] = q.front(); q.pop();

        bestDiff = min(bestDiff, abs(M - (a+b)));

        if (steps == K) continue;

        vector<pair<int,int>> nextStates;

        nextStates.push_back({X, b});
        nextStates.push_back({a, Y});

        nextStates.push_back({0, b});
        nextStates.push_back({a, 0});

        int pourAB = min(a, Y-b);
        nextStates.push_back({a - pourAB, b + pourAB});

        int pourBA = min(b, X-a);
        nextStates.push_back({a + pourBA, b - pourBA});

        for (auto [na, nb] : nextStates) {
            if (!visited[na][nb][steps+1]) {
                visited[na][nb][steps+1] = true;
                q.push({na, nb, steps+1});
            }
        }
    }

    cout << bestDiff << "\n";
}