#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N; cin >> N;
    vector<vector<int>> matches(4, vector<int>(4, 0));

    for (int i = 0; i < N; i++) {
        int a; int b; cin >> a >> b;
        matches[a][b] += 1;
    }
    int scenario1 = matches[1][2] + matches[2][3] + matches[3][1];
    int scenario2 = matches[2][1] + matches[3][2] + matches[1][3];
    cout << max(scenario1, scenario2) << endl;
}