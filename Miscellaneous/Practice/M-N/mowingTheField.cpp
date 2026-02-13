#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N; cin >> N;
    map<vector<int>, vector<int>> coordToTimes;
    coordToTimes[{0, 0}] = {0};
    unordered_map<string, vector<int>> directionVectors = {
        {"N", {0, 1}}, {"E", {1, 0}}, {"S", {0, -1}},  {"W", {-1, 0}}
    };
    
    vector<int> xy = {0, 0}; int t = 1;
    for (int i = 0; i < N; i++) {
        string dir; int dist; cin >> dir >> dist;
        vector<int> dxy = directionVectors[dir];
        for (int j = 0; j < dist; j++) {
            xy[0] += dxy[0]; xy[1] += dxy[1];
            if (coordToTimes.count(xy)) coordToTimes[xy].push_back(t);
            else coordToTimes[xy] = {t};
            t += 1;
        }
    }

    int min_growth_time = 1e9;
    for (const auto& [coord, times] : coordToTimes) {
        if (times.size() > 1) {
            for (int i = 1; i < times.size(); i++) {
                min_growth_time = min(min_growth_time, times[i] - times[i-1]);
            }
        }
    }

    if (min_growth_time == 1e9) cout << -1 << endl;
    else cout << min_growth_time << endl;


    return 0;
}