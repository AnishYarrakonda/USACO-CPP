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

int N, M;

bool valid(vint& cows, vint& components) {
    for (int i = 1; i < N+1; i++) if (components[i] != components[cows[i]]) return false;
    return true;
}

void bfs(vector<vector<pii>>& wormholes, vint& components, int minWidth) {
    int num = 1;

    for (int node = 1; node < N+1; node++) {
        if (components[node]) continue;

        components[node] = num;
        queue<int> q; q.push(node);

        while (!q.empty()) {
            int currNode = q.front(); q.pop();

            for (auto wormhole : wormholes[currNode]) {
                int adjNode = wormhole.first;
                int width = wormhole.second;
                
                if (width < minWidth || components[adjNode]) continue;

                components[adjNode] = num;
                q.push(adjNode);
            }
        }
        num++;
    }
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin >> N >> M;
    vint cows(N+1);
    for (int i = 1; i < N+1; i++) cin >> cows[i];

    vint widths;
    vector<vector<pii>> wormholes(N+1);
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        wormholes[a].push_back({b, w});
        wormholes[b].push_back({a, w});
        widths.push_back(w);
    }

    bool sorted = true;
    for (int i = 1; i <= N; i++) {
        if (cows[i] != i) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << -1 << '\n';
        return 0;
    }

    sort(widths.begin(), widths.end());
    widths.erase(unique(widths.begin(), widths.end()), widths.end());

    int l = 0, r = widths.size() - 1;
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int minWidth = widths[mid];
        
        vint components(N+1, 0);
        bfs(wormholes, components, minWidth);

        if (valid(cows, components)) {l = mid+1; ans = minWidth;}
        else r = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}