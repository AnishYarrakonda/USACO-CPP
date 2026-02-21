/*
Programmer: Anish Yarrakonda
Date: Jan 30
Problem 2
(-_-) MORE LOCKED IN!!
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // fast input/ouput
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read in all inputs
    int N, C;
    cin >> N >> C;

    // maximum allowed participants per criterion
    vector<int> capacity(C + 1);
    for (int i = 1; i <= C; ++i) cin >> capacity[i];

    // the order in which participants arrive
    vector<int> participants(N + 1);
    for (int i = 1; i <= N; ++i) cin >> participants[i];

    // list of criteria each participant is eligible for
    vector<vector<int>> criteria(N + 1);
    for (int r = 1; r <= N; ++r) {
        int numCrit; 
        cin >> numCrit;
        criteria[r].resize(numCrit);
        for (int j = 0; j < numCrit; ++j) cin >> criteria[r][j];
    }

    for (int r = 1; r <= N; ++r) {
        sort(criteria[r].begin(), criteria[r].end());
    }

    // trackers
    vector<int> position(N + 1, 0);
    vector<char> isPresent(N + 1, 0);
    vector<char> isAssigned(N + 1, 0);
    vector<int> rank(N + 1, 0);
    vector<ll> result(N);

    /* 
    GREEDY ALGORITHM WITH A PRIORITY QUEUE BELOW
        - greedily assigns values inside the pq
        - finds the best case scenario
        - improved efficiency from O(N^2) to O(N)
        - muy bien chico
    */

    ll totalRankSum = 0;

    vector<priority_queue<pair<int, int>>> critQueues(C + 1);

    for (int idx = N; idx >= 1; --idx) {
        int participantId = participants[idx];
        rank[participantId] = participantId;
        isPresent[participantId] = 1;
        position[participantId] = 0;

        int current = participantId;

        while (true) {
            if (position[current] >= (int)criteria[current].size()) {
                isAssigned[current] = 0;
                break;
            }

            int critIndex = criteria[current][position[current]];
            critQueues[critIndex].push({rank[current], current});
            totalRankSum += rank[current];
            isAssigned[current] = 1;

            if ((int)critQueues[critIndex].size() <= capacity[critIndex]) break;

            auto worst = critQueues[critIndex].top();
            critQueues[critIndex].pop();

            int worstId = worst.second;
            int worstRank = worst.first;
            totalRankSum -= worstRank;

            if (worstId == current) {
                position[current]++;
                continue;
            } else {
                isAssigned[worstId] = 0;
                position[worstId]++;
                current = worstId;
            }
        }

        result[idx - 1] = totalRankSum;
    }

    // output the results without buffer
    for (int i = 0; i < N; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}