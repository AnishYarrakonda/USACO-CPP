#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, N; cin >> W >> N;
    vector<pair<string,int>> completeWords(W);
    for (int i = 0; i < W; i++) {
        string word; cin >> word;
        completeWords[i] = {word, i + 1};
    }

    sort(completeWords.begin(), completeWords.end());
    
    for (int i = 0; i < N; i++) {
        int K; string word; cin >> K >> word;
        int idx = lower_bound(completeWords.begin(), completeWords.end(), make_pair(word, 0))-completeWords.begin();
        idx += K - 1;
        if (idx < W && completeWords[idx].first.substr(0, word.size()) == word) {
            cout << completeWords[idx].second << '\n';
        } else cout << -1 << '\n';
    }
}