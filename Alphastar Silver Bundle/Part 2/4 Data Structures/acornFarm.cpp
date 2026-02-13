#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Measurement {
    int day, id, change;
};

bool compareMeas(Measurement a, Measurement b) {
    return a.day < b.day;
}

int main() {
    int N;
    long long A;
    cin >> N >> A;

    vector<Measurement> log(N);
    for (int i = 0; i < N; i++) {
        cin >> log[i].day >> log[i].id >> log[i].change;
    }
    sort(log.begin(), log.end(), compareMeas);

    map<int, long long> treeOutputs;
    multiset<long long> allOutputs;
    
    // We treat the "many other trees" as a very large constant 
    // to ensure there's always something at the initial value A.
    // However, for this specific problem, tracking just the trees that 
    // move is enough if we represent the "base" trees correctly.
    allOutputs.insert(A); 
    
    int changes = 0;

    for (auto& m : log) {
        long long oldVal = treeOutputs.count(m.id) ? treeOutputs[m.id] : A;
        long long oldMax = *allOutputs.rbegin();
        int oldMaxCount = allOutputs.count(oldMax);

        // Boolean: Was this specific tree a leader before?
        bool wasLeader = (oldVal == oldMax);

        // Update frequencies
        auto it = allOutputs.find(oldVal);
        if (it != allOutputs.end()) allOutputs.erase(it);
        
        treeOutputs[m.id] = oldVal + m.change;
        allOutputs.insert(treeOutputs[m.id]);

        long long newMax = *allOutputs.rbegin();
        int newMaxCount = allOutputs.count(newMax);
        
        // Boolean: Is this specific tree a leader now?
        bool isLeader = (treeOutputs[m.id] == newMax);

        // Logic to determine if the ribbon placement changed:
        if (wasLeader) {
            // It was a leader but now things changed
            if (!isLeader || oldMaxCount != 1 || newMaxCount != 1) {
                changes++;
            }
        } else if (isLeader) {
            // It wasn't a leader, but now it is
            changes++;
        }
    }

    cout << changes+1 << endl;
    return 0;
}