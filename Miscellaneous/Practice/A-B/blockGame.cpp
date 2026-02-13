#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N; cin >> N;
    vector<vector<string>>blocks(N, vector<string>(2));
    for (int i = 0; i < N; i++) cin >> blocks[i][0] >> blocks[i][1];
    vector<int> copies(26);
    for (int i = 0; i < 26; i++) {
        char letter = static_cast<char>(i+97);
        int copiesNeeded = 0;
        for (int j = 0; j < N; j++) {
            int count1 = std::count(blocks[j][0].begin(), blocks[j][0].end(), letter);
            int count2 = std::count(blocks[j][1].begin(), blocks[j][1].end(), letter);
            copiesNeeded += std::max(count1, count2);
        }
        copies[i] = copiesNeeded;
    }
    for (int copiesNeeded: copies) cout << copiesNeeded << endl;
    return 0;
}