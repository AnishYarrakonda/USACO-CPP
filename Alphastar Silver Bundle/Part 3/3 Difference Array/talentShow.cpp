#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // Frequency arrays
    vector<long long> freqA(M + 1, 0);
    vector<long long> freqB(M + 1, 0);
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        freqA[a]++;
        freqB[b]++;
    }
    
    // Convolve freqA with itself to get sum frequencies
    vector<long long> sumA(2*M + 1, 0);
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= M; j++) {
            sumA[i + j] += freqA[i] * freqA[j];
        }
    }
    
    // Convolve freqB with itself
    vector<long long> sumB(2*M + 1, 0);
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= M; j++) {
            sumB[i + j] += freqB[i] * freqB[j];
        }
    }
    
    // Build difference array
    // sumA[s] = number of pairs where a_i + a_j = s (they start at K=s)
    // sumB[t] = number of pairs where b_i + b_j = t (they end at K=t)
    vector<long long> diff(2*M + 2, 0);
    
    for(int s = 0; s <= 2*M; s++) {
        diff[s] += sumA[s];      // pairs start contributing
    }
    
    for(int t = 0; t <= 2*M; t++) {
        diff[t + 1] -= sumB[t];  // pairs stop contributing
    }
    
    // Compute prefix sum
    long long count = 0;
    for(int k = 0; k <= 2*M; k++) {
        count += diff[k];
        cout << count << '\n';
    }
    
    return 0;
}