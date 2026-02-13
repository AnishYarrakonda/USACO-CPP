#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef long long ll;

bool haveNoIntersection(const unordered_set<string>& set1,
                        const unordered_set<string>& set2) {
    for (const auto& vec : set1) if (set2.count(vec) > 0) return false;
    return true;
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<string> spotty;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        spotty.push_back(input);
    }
    vector<string> plain;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        plain.push_back(input);
    }

    int count = 0;
    for (int i = 0; i < M; i++){
        for (int j = i+1; j < M; j++) {
            for (int k = j+1; k < M; k++) {
                unordered_set<string> spottyTrios;
                for (string cow : spotty) spottyTrios.insert({string(1, cow[i]) + cow[j] + cow[k]});
                unordered_set<string> plainTrios;
                for (string cow : plain) plainTrios.insert({string(1, cow[i]) + cow[j] + cow[k]});
                count += haveNoIntersection(spottyTrios, plainTrios);
            }
        }
    }

    cout << count << endl;

    return 0;
}