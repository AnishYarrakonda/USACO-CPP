#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

void applySwaps(vector<int>& v, int A1, int A2, int B1, int B2) {
    reverse(v.begin() + A1, v.begin() + A2 + 1);
    reverse(v.begin() + B1, v.begin() + B2 + 1);
}

int main() {
    freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);

    int N, K;
    cin >> N >> K;
    int A1, A2;
    cin >> A1 >> A2;
    int B1, B2;
    cin >> B1 >> B2;

    vector<int> current(N + 1);
    // Initialize 1-based vector
    for (int i = 1; i <= N; ++i) {
        current[i] = i;
    }
    vector<int> initial = current;
    int steps = 0;

    // Simulate to find the cycle length of the permutation
    do {
        applySwaps(current, A1, A2, B1, B2);
        steps++;
    } while (current != initial);

    // K modulo the cycle length
    int remainingSteps = K % steps;

    // Apply the remaining steps to get the final state
    vector<int> finalState = initial;
    for (int i = 0; i < remainingSteps; ++i) {
        applySwaps(finalState, A1, A2, B1, B2);
    }

    // Print the final state (1-based indices, outputting the value)
    for (int i = 1; i <= N; ++i) {
        cout << finalState[i] << "\n";
    }

    return 0;
}