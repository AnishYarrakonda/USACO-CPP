#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <math.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vint;
typedef long long ll;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int N; cin >> N;
    
    map<int, int> outputToCows;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        outputToCows[y] = x;
    }

    int worstPairSum = 0;

    while (!outputToCows.empty()) {
        auto itFirst = outputToCows.begin();
        auto itLast = prev(outputToCows.end());

        int firstOutput = itFirst->first;
        int firstCount = itFirst->second;
        int lastOutput = itLast->first;
        int lastCount = itLast->second;

        int pairs = min(firstCount, lastCount);

        worstPairSum = max(worstPairSum, firstOutput + lastOutput);

        outputToCows[firstOutput] -= pairs;
        if (firstOutput != lastOutput) outputToCows[lastOutput] -= pairs;

        if (firstOutput == lastOutput) {
            outputToCows.erase(itFirst);
        } else {
            if (outputToCows[firstOutput] == 0) outputToCows.erase(itFirst);
            if (outputToCows[lastOutput] == 0) outputToCows.erase(itLast);
        }
    }

    cout << worstPairSum;

    return 0;
}