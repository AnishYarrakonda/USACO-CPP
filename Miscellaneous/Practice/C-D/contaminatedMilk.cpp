#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> intersect_all(const vector<unordered_set<int>>& sets) {
    if (sets.empty()) return {};

    int idx = 0;
    for (int i = 1; i < (int)sets.size(); i++) {
        if (sets[i].size() < sets[idx].size()) {
            idx = i;
        }
    }

    unordered_set<int> result;

    for (int x : sets[idx]) {
        bool ok = true;
        for (int i = 0; i < (int)sets.size(); i++) {
            if (i == idx) continue;
            if (!sets[i].count(x)) {
                ok = false;
                break;
            }
        }
        if (ok) result.insert(x);
    }

    return result;
}


int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int N; int M; int D; int S;
    cin >> N >> M >> D >> S;

    vector<unordered_set<int>> drankMilk(M+1);
    vector<vector<array<int, 2>>> peopleDrank(N+1);

    for (int i = 0; i < D; i++) {
        int p; int m; int t;
        cin >> p >> m >> t;
        array<int,2> drank = {m, t};
        peopleDrank[p].push_back(drank);
        drankMilk[m].insert(p);
    }

    vector<unordered_set<int>> allPossibleMilks;

    for (int i = 0; i < S; i++) {
        int p; int t;
        cin >> p >> t;

        unordered_set<int> possibleMilks;
        for (int j = 0; j < peopleDrank[p].size(); j++) {
            if (peopleDrank[p][j][1] < t) {
                possibleMilks.insert(peopleDrank[p][j][0]);
            }
        }

        allPossibleMilks.push_back(possibleMilks);
    }

    unordered_set<int> badMilks = intersect_all(allPossibleMilks);

    int mostSick = 0;
    for (int milk: badMilks) {
        int potential = drankMilk[milk].size();
        mostSick = max(mostSick, potential);
    }

    cout << mostSick << endl;
    
    return 0;
}