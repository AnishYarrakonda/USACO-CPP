#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int N, P; cin >> N >> P;
    vector<int> buckets(N);
    for (int i = 0; i < N; i++) cin >> buckets[i];

    vector<int> dist(P, -1);
    queue<int> q;

    dist[A % P] = 0;
    q.push(A % P);

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        if (curr == B % P) {
            cout << dist[curr] << "\n";
            return 0;
        }

        for (int b : buckets) {
            int next = (1LL * curr * b) % P;
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    cout << -1 << "\n";
}