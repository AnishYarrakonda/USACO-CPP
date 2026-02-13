#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int M, N, K; cin >> M >> N >> K;
    vector<string> enlarged(K*M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char chr; cin >> chr;
            for (int a = 0; a < K; a++) {
                for (int b = 0; b < K; b++) {
                enlarged[i*K+a] += chr;
                }
            }
        }
    }
    for (int i = 0; i < K*M; i++) cout << enlarged[i] << endl;

    return 0;
}