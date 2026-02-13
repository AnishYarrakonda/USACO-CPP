#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool areEqual(int N, const vector<vector<char>>& piece1, const vector<vector<char>>& piece2) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (piece1[x][y] != piece2[x][y]) {
                return false;
            }
        }
    }
    return true;
}

bool invalidSuperimposition(
    int i, int j, int N,
    const vector<vector<vector<char>>>& pieces,
    vector<vector<char>>& piece
) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            char chr = pieces[j][x][y];
            if (chr == '#') {
                if (piece[x][y] == '#') {
                    return true;
                } else {
                    piece[x][y] = chr;
                }
            }
        }
    }
    return false;
}

bool allSuperImpositions(int i, int j, int N, const vector<vector<vector<char>>>& pieces) {
    for (int u1 = 1-N; u1 < N; u1++) {
        for (int v1 = 1-N; v1 < N; v1++) {
            for (int u2 = 1-N; u2 < N; u2++) {
                for (int v2 = 1-N; v2 < N; v2++) {
                    
                    vector<vector<char>> combined(N, vector<char>(N, '.'));
                    bool overlap = false;
                    
                    for (int x = 0; x < N; x++) {
                        for (int y = 0; y < N; y++) {
                            if (pieces[i][x][y] == '#') {
                                int nx = x + u1, ny = y + v1;
                                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                                    combined[nx][ny] = '#';
                                }
                            }
                        }
                    }
                    
                    for (int x = 0; x < N; x++) {
                        for (int y = 0; y < N; y++) {
                            if (pieces[j][x][y] == '#') {
                                int nx = x + u2, ny = y + v2;
                                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                                    if (combined[nx][ny] == '#') {
                                        overlap = true;
                                        break;
                                    }
                                    combined[nx][ny] = '#';
                                }
                            }
                        }
                        if (overlap) break;
                    }
                    
                    if (!overlap && areEqual(N, combined, pieces[0])) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);

    int N; int K; cin >> N >> K;
    vector<vector<vector<char>>> pieces(K+1);

    for (int i = 0; i < K+1; i++) {
        vector<vector<char>> piece(N);
        for (int j = 0; j < N; j++) {
            string input; cin >> input;
            for (char c: input) {
                piece[j].push_back(c);
            }
        }
        pieces[i] = piece;
    }

    for (int i = 1; i < K+1; i++) {
        for (int j = i+1; j < K+1; j++) {
            if (allSuperImpositions(i, j, N, pieces)) {
                cout << min(i, j) << " " << max(i, j) << endl;
            }
        }
    }

    return 0;
}