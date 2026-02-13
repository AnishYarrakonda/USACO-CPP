#include <iostream>
#include <vector>
using namespace std;

void flip(int x, int y, vector<vector<bool>>& grid) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            grid[i][j] = !grid[i][j];
        }
    }
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int N; cin >> N;
    vector<vector<bool>> grid(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++) {
            grid[i][j] = (input[j] == '1');
        }
    }

    int operations = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (grid[i][j]) {
                flip(i, j, grid);
                operations++;
            }
        }
    }

    cout << operations << endl;
    return 0;
}
