#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
typedef vector<int> vint;
typedef pair<long long, int> pll;
typedef long long ll;

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int A, B, N; cin >> A >> B >> N;
    
    vector<vector<pll>> costMatrix(1001, vector<pll>(1001, {1e18, 1e9}));
    
    for (int i = 0; i < 1001; i++) {
        costMatrix[i][i] = {0, 0};
    }

    for (int i = 0; i < N; i++) {
        ll cost; int numCities; 
        cin >> cost >> numCities;
        vint route(numCities);
        for (int j = 0; j < numCities; j++) cin >> route[j];
        
        for (int x = 0; x < numCities; x++) {
            for (int y = x + 1; y < numCities; y++) {
                int cityU = route[x];
                int cityV = route[y];
                int hops = y - x;
                costMatrix[cityU][cityV] = min(costMatrix[cityU][cityV], {cost, hops});
            }
        }
    }

    vector<bool> visited(1001, false);
    vector<pll> dist(1001, {1e18, 1e9});
    dist[A] = {0, 0};
    
    for (int iter = 0; iter < 1001; iter++) {
        int u = -1;
        for (int i = 0; i < 1001; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        
        if (u == -1 || dist[u].first >= 1e18) break;
        
        visited[u] = true;
        
        for (int v = 0; v < 1001; v++) {
            if (costMatrix[u][v].first < 1e18) {
                pll newDist = {dist[u].first + costMatrix[u][v].first,
                               dist[u].second + costMatrix[u][v].second};
                dist[v] = min(dist[v], newDist);
            }
        }
    }
    
    if (dist[B].first >= 1e18) {
        cout << "-1 -1" << endl;
    } else {
        cout << dist[B].first << " " << dist[B].second << endl;
    }

    return 0;
}