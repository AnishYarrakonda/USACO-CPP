/*
Programmer: Anish Yarrakonda
Date: Jan 30
Problem 1
(-_-) LOCKED IN!
*/

#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
    // fast input/ouput
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read in T (subcases) and mode (0 or 1)
    int T, mode;
    cin >> T >> mode;

    // do all subcases
    while (T--) {
        // read in N
        int N;
        cin >> N;

        // read in the left and right string
        string leftStr, rightStr;
        cin >> leftStr >> rightStr;

        // conver the strings into binary arrays for efficiency and ease of use
        // much better now!
        vector<int> leftVals(N + 1), rightVals(N + 1);
        for (int i = 1; i <= N; i++) leftVals[i] = (leftStr[i - 1] == 'N');
        for (int i = 1; i <= N; i++) rightVals[i] = (rightStr[i - 1] == 'N');

        // count the zeros on both sides
        int leftZeroCount = 0, rightZeroCount = 0;
        for (int i = 1; i <= N; i++) {
            if (leftVals[i] == 0) leftZeroCount++;
            if (rightVals[i] == 0) rightZeroCount++;
        }

        // impossible check
        if (leftZeroCount != rightZeroCount) {
            cout << "NO\n";
            continue;
        }

        // XOR parity check for right constraints because must satsify either lying lying or truth truth (++ and -- are both +)
        int xorRight = 0;
        for (int i = 1; i <= N; i++) xorRight ^= rightVals[i];
        if (xorRight) {
            cout << "NO\n";
            continue;
        }

        // build and adj list for the graph
        vector<vector<int>> adj(2);
        for (int i = 1; i <= N; i++) adj[rightVals[i]].push_back(i);

        // detect the impooooossible test cases
        // these are sometimes annoying to catch
        bool hasZero = !adj[0].empty();
        bool hasOne = !adj[1].empty();
        bool hasMismatch = false;
        for (int i = 1; i <= N; i++) {
            if (rightVals[i] != leftVals[i]) {
                hasMismatch = true;
                break;
            }
        }

        // impossible check from previous run
        if (hasZero && hasOne && !hasMismatch) {
            cout << "NO\n";
            continue;
        }

        // choose a starting node
        vector<vector<int>> adjCopy = adj;
        int startNode = -1;
        if (hasZero) startNode = 0;
        else if (hasOne) startNode = 1;
        else {
            cout << "NO\n";
            continue;
        }

        // run our greedy algorithmic traversal
        vector<int> edgeOrder;
        edgeOrder.reserve(N);
        vector<int> nodeStack;
        nodeStack.reserve(N + 5);
        vector<int> tempEdgeStack;
        tempEdgeStack.reserve(N + 5);

        nodeStack.push_back(startNode);
        while (!nodeStack.empty()) {
            int currentNode = nodeStack.back();
            if (!adjCopy[currentNode].empty()) {
                int edge = adjCopy[currentNode].back();
                adjCopy[currentNode].pop_back();
                nodeStack.push_back(leftVals[edge]);
                tempEdgeStack.push_back(edge);
            } else {
                nodeStack.pop_back();
                if (!tempEdgeStack.empty()) {
                    edgeOrder.push_back(tempEdgeStack.back());
                    tempEdgeStack.pop_back();
                }
            }
        }

        // check if the traversal used 
        if ((int)edgeOrder.size() != N) {
            cout << "NO\n";
            continue;
        }

        // jajaja chico
        bool solutionFound = false;
        vector<int> finalValues;
        for (int initVal = 0; initVal <= 1 && !solutionFound; ++initVal) {
            vector<int> b(N + 1, -1);
            int firstEdge = edgeOrder[0];
            b[firstEdge] = initVal;

            for (int i = 0; i < N - 1; ++i) {
                int current = edgeOrder[i];
                int next = edgeOrder[i + 1];
                b[next] = b[current] ^ rightVals[current];
            }

            bool valid = true;
            for (int i = 0; i < N; ++i) {
                int current = edgeOrder[i];
                int next = edgeOrder[(i + 1) % N];
                int prev = edgeOrder[(i - 1 + N) % N];

                if (rightVals[current] != (b[current] ^ b[next])) { valid = false; break; }
                if (leftVals[current] != (b[current] ^ b[prev])) { valid = false; break; }
            }

            if (valid) {
                solutionFound = true;
                finalValues = std::move(b);
            }
        }

        if (!solutionFound) {
            cout << "NO\n";
            continue;
        }

        // output valid "YES" result
        cout << "YES\n";
        if (mode == 1) {
            for (int i = 0; i < N; i++) {
                if (i) cout << ' ';
                cout << edgeOrder[i];
            }
            cout << '\n';

            for (int i = 0; i < N; i++) {
                int id = edgeOrder[i];
                cout << (finalValues[id] == 0 ? 'J' : 'N');
            }
            cout << '\n';
        }
    }

    return 0;
}