#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef vector<int> vint;
typedef long long ll;

int dijkstra(int N, vector<vector<vint>> adj, int minC) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vint distArr(N+1, 1e9); distArr[1] = 0; pq.push({0, 1});

    while (!pq.empty()) {
        int dist = pq.top().first; int node = pq.top().second; pq.pop();

        if (dist > distArr[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it[0]; int lat = it[1]; int C = it[2];

            if (C < minC) continue;

            int newDist = dist + lat;

            if (newDist < distArr[adjNode]) {
                distArr[adjNode] = newDist;
                pq.push({newDist, adjNode});
            }
        }
    }
    return distArr[N];
}

int main() {
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);

    int N, M, X; cin >> N >> M >> X;
    vector<vector<vint>> adj(N+1);
    set<int, greater<int>> capacities;
    for (int a = 0; a < M; a++) {
        int i, j, L, C; cin >> i >> j >> L >> C;
        adj[i].push_back({j, L, C});
        adj[j].push_back({i, L, C});
        capacities.insert(C);
    }

    int minRate = 1e9;
    for (int C : capacities) {
        minRate = min(dijkstra(N, adj, C) + X/C, minRate);
    }

    cout << minRate;

    return 0;
}