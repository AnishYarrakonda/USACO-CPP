#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    
    sort(pos.begin(), pos.end());
    
    // Calculate minimum moves using two pointers
    int minMoves = n; // worst case: move all pebbles
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        // Extend j to include all positions within a window of size n
        while (j < n && pos[j] - pos[i] < n) {
            j++;
        }
        
        // Number of pebbles already in this window [pos[i], pos[i]+n-1]
        int pebblesInWindow = j - i;
        
        // Special case: if we have exactly n-1 pebbles and they are consecutive
        // This means there's exactly 1 gap in the middle, which requires 2 moves
        if (pebblesInWindow == n - 1 && pos[j-1] - pos[i] == n - 2) {
            minMoves = min(minMoves, 2);
        } else {
            minMoves = min(minMoves, n - pebblesInWindow);
        }
    }
    
    // Calculate maximum moves
    // We can fill all gaps except we can't completely fill the gap next to one endpoint
    int totalRange = pos[n-1] - pos[0];
    int gapAfterFirst = pos[1] - pos[0] - 1;  // gap between first and second pebble
    int gapBeforeLast = pos[n-1] - pos[n-2] - 1;  // gap between last and second-to-last
    
    int maxMoves = totalRange - (n - 1) - min(gapAfterFirst, gapBeforeLast);
    
    cout << minMoves << "\n";
    cout << maxMoves << "\n";
    
    return 0;
}