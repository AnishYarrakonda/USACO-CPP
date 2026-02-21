// Programmer: Anish Yarrakonda
// Date: Jan 31, 2026
// Problem 2

/*
Plan:
    - Dijkstra-ish approach
        - Instead of minimizing numeric distance, we minimize
        the lexicographic order of the path string
        - Process all nodes with the same optimal prefix together
        - At each step, only expand edges with the smallest
        possible character
    - *ISSUE*
        - must handle loops where the characters can just repeat infinitely
        - for example instead of ever reaching node two by adding the letter b:
            - it is optimal to self cycle on node with letter a to geta better answer
            - handle this using bfs at the beginning
*/

// set up
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> using p = pair<A,B>;
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vector<int>;

// function that solves each test case
void solve() {
    // read in inputs
    int N, M;
    cin >> N >> M;

    // adj list
    vv<p<int,char>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to;
        char label;
        cin >> from >> to >> label;
        adj[from].push_back({to, label});
        adj[to].push_back({from, label});
    }

    // dist[i] stores the length of the lexi-min path to node i
    vi dist(N + 1, -1);

    // nodes that are currently reachable using the best possible prefix
    vi current_nodes;
    current_nodes.push_back(1);
    dist[1] = 0;

    // stores the next nodes
    vi next_nodes;
    v<bool> in_next(N + 1, false);

    // stores current dist
    int current_dist = 0;

    // expand topologically from node 1
    while (!current_nodes.empty()) {
        // this is the first character after the letter z in ASCII, so it acts as a place holder for min_c
        char min_c = '{';   
        bool found = false;

        // find the smallest outgoing character from this level in our level order traversal
        for (int node : current_nodes) {
            for (auto &edge : adj[node]) {
                if (edge.second < min_c) {
                    min_c = edge.second;
                    found = true;
                }
            }
        }

        // if there are no more edges to expand, then we can stop
        if (!found) break;
        next_nodes.clear();

        // only expand to edges that match our smallest character
        for (int node : current_nodes) {
            for (auto &edge : adj[node]) {
                if (edge.second == min_c) {
                    int next_node = edge.first;
                    if (dist[next_node] == -1 && !in_next[next_node]) {
                        dist[next_node] = current_dist + 1;
                        in_next[next_node] = true;
                        next_nodes.push_back(next_node);
                    }
                }
            }
        }

        // reset stuff for the next time
        for (int node : next_nodes) in_next[node] = false;

        // move to next level
        current_nodes = next_nodes;
        current_dist++;
    }

    // output results
    for (int i = 1; i <= N; ++i) {
        cout << dist[i] << (i == N ? "\n" : " ");
    }
}

// main function
int main() {
    // fast i/o
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve all test cases
    int T; cin >> T;
    while (T--) solve();

    return 0;
}