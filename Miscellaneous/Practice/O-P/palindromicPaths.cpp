#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);

    int N; cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    unordered_set<string> front;
    for (int i = 0; i < (1 << N); i++) {
        string path = "";
        int x = 0; int y = 0;
        for (int j = 0; j < N-1; j++) {
            if ((i >> j) & 1) x++;
            else y++;
            path += grid[x][y];
        }
        path += char(x);
        front.insert(path);
    }

    unordered_set<string> back;
    for (int i = 0; i < (1 << N); i++) {
        string path = "";
        int x = N-1; int y = N-1;
        for (int j = 0; j < N-1; j++) {
            if ((i >> j) & 1) x--;
            else y--;
            path += grid[x][y];
        }
        path += char(x);
        back.insert(path);
    }

    unordered_set<string> truePaths; 
    int total = 0;
    for (auto path : front) {
        if (back.count(path)) {
            path.pop_back();
            truePaths.insert(path);
        }
    }

    cout << truePaths.size() << endl;
    
    return 0;
}