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

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int A, B, N; cin >> A >> B >> N;
    vector<pair<int, vint>> routes(N);

    for (int i = 0; i < N; i++) {
        int cost, numCities; cin >> cost >> numCities;
        vint route(numCities);
        for (int j = 0; j < numCities; j++) {
            cin >> route[j];
        }
        routes[i] = {cost, route};
    }

    int minCost = 1e9;
    bool changed = false;

    for (auto route : routes) {
        int cost = route.first; vint cities = route.second;

        int idxA = -1, idxB = -1;

        auto itA = find(cities.begin(), cities.end(), A);
        if (itA != cities.end()) idxA = itA - cities.begin();

        auto itB = find(cities.begin(), cities.end(), B);
        if (itB != cities.end()) idxB = itB - cities.begin();

        if (idxA == -1 || idxB == -1 || idxA > idxB) continue;
        else {minCost = min(cost, minCost); changed = true;}
    }

    if (!changed) cout << -1 << endl;
    else cout << minCost;

    return 0;
}