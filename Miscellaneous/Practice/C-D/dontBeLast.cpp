#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int N; cin >> N;
    unordered_map<string, int> cowToMilk = {
        {"Annabelle", 0}, {"Bessie", 0}, {"Daisy", 0}, {"Elsie", 0},
        {"Gertie", 0},  {"Henrietta", 0}, {"Maggie", 0}
    };

    for (int i = 0; i < N; i++) {
        string cow; int milk; cin >> cow >> milk;
        cowToMilk[cow] += milk;
    }

    set<int> milkVals;
    for (const auto& [cow, milk] : cowToMilk) milkVals.insert(milk);
    vector<int> vals(milkVals.begin(), milkVals.end());

    if (vals.size() == 1) cout << "Tie" << endl;
    else {
        vector<string> bestCows;
        for (const auto& [cow, milk] : cowToMilk) {
            if (milk == vals[1]) bestCows.push_back(cow);
        }
        if (bestCows.size() > 1) cout << "Tie" << endl;
        else cout << bestCows[0] << endl;
    }
}