#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef long long ll;

vint dijkstra(int N, vector<vint> adj, int S) {
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    vint distArr(N+1, 1e9); distArr[S] = 0; pq.push({0, S});

    while (!pq.empty()) {
        int dist = pq.top().first; int node = pq.top().second; pq.pop();

        if (dist > distArr[node]) continue;

        for (int adjNode : adj[node]) {
            int newDist = dist + 1;
            if (newDist < distArr[adjNode]) {
                distArr[adjNode] = newDist;
                pq.push({newDist, adjNode});
            }
        }
    }
    return distArr;
}

int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    int B, E, P, N, M; cin >> B >> E >> P >> N >> M;
    vector<vint> adj(N+1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vint bessieDists = dijkstra(N, adj, 1);
    vint elsieDists = dijkstra(N, adj, 2);
    vint barnDists = dijkstra(N, adj, N);
    
    int minEnergy = B*bessieDists[N] + E*elsieDists[N];
    for (int i = 1; i < N+1; i++) {
        int piggyback = B*bessieDists[i] + E*elsieDists[i] + P*barnDists[i];
        minEnergy = min(minEnergy, piggyback);
    }

    cout << minEnergy << endl;

    return 0;
}