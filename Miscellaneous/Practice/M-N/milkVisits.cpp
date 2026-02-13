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

void dfs(int node, int region, vector<vint>& adj, string& breeds, vint& regions) {
    char c = breeds[node];
    queue<int> q;
    q.push(node);
    regions[node] = region;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        
        for (auto adjNode : adj[currNode]) {
            if (!regions[adjNode] && breeds[adjNode] == c) {
                q.push(adjNode);
                regions[adjNode] = region;
            }
        }
    }
}


int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M; cin >> N >> M;
    string breeds; cin >> breeds; breeds = " " + breeds;
    vector<vint> adj(N+1);

    for (int i = 0; i < N-1; i++) {
        int X, Y; cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    vint regions(N+1, 0);
    int region = 1;
    for (int node = 1; node <= N; node++) {
        if (!regions[node]) {
            dfs(node, region, adj, breeds, regions);
            region++;
        }
    }


    for (int i = 0; i < M; i++) {
        int A, B; char C; cin >> A >> B >> C;
        if (regions[A] != regions[B]) cout << 1;
        else if (breeds[A] == C) cout << 1;
        else cout << 0;
    }

    return 0;
}