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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            int cost = routes[i].first + routes[j].first;
            if (cost >= minCost) continue;
            
            for (int cityC : routes[i].second) {
                auto it = find(routes[j].second.begin(), routes[j].second.end(), cityC);
                if (it == routes[j].second.end()) continue;
                
                int posA_i = -1, posC_i = -1;
                for (int k = 0; k < routes[i].second.size(); k++) {
                    if (routes[i].second[k] == A) posA_i = k;
                    if (routes[i].second[k] == cityC) posC_i = k;
                }

                int posC_j = -1, posB_j = -1;
                for (int k = 0; k < routes[j].second.size(); k++) {
                    if (routes[j].second[k] == cityC) posC_j = k;
                    if (routes[j].second[k] == B) posB_j = k;
                }
                
                if (posA_i != -1 && posC_i != -1 && posA_i < posC_i &&
                    posC_j != -1 && posB_j != -1 && posC_j < posB_j) {
                    minCost = min(minCost, cost);
                    changed = true;
                }
            }
        }
    }

    if (!changed) cout << -1 << endl;
    else cout << minCost;

    return 0;
}