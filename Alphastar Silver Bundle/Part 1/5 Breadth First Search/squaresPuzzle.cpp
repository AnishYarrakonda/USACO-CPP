#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi transformA(vi state) {

    return {state[7], state[6], state[5], state[4], 
            state[3], state[2], state[1], state[0]};
}

vi transformB(vi state) {

    return {state[3], state[0], state[1], state[2],
            state[5], state[6], state[7], state[4]};
}

vi transformC(vi state) {

    return {state[0], state[6], state[1], state[3],
            state[4], state[2], state[5], state[7]};
}

int main() {
    vi target(8);
    for (int i = 0; i < 8; i++) {
        cin >> target[i];
    }

    vi initial = {1, 2, 3, 4, 5, 6, 7, 8};

    queue<pair<vi, string>> q;
    map<vi, bool> visited;

    q.push({initial, ""});
    visited[initial] = true;

    while (!q.empty()) {
        auto [current, path] = q.front();
        q.pop();

        if (current == target) {
            cout << path.length() << endl;
            if (path.empty()) {
                cout << endl;
            } else {
                cout << path << endl;
            }
            return 0;
        }

        vector<pair<vi, char>> nextStates = {
            {transformA(current), 'A'},
            {transformB(current), 'B'},
            {transformC(current), 'C'}
        };

        for (auto [nextState, move] : nextStates) {
            if (!visited[nextState]) {
                visited[nextState] = true;
                q.push({nextState, path + move});
            }
        }
    }

    return 0;
}