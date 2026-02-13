#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define rep(i,a,b) for(int i = a; i < (b); i++)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    vi books(N);
    rep(i,0,N) cin >> books[i];
    
    // Create sorted version to know target positions
    vi sorted_books = books;
    sort(all(sorted_books));
    
    // Map each book size to its target position
    map<int, int> target_pos;
    rep(i,0,N) {
        target_pos[sorted_books[i]] = i;
    }
    
    // Find cycles
    vector<bool> visited(N, false);
    ll total_cost = 0;
    int global_min = *min_element(all(books));
    
    rep(i,0,N) {
        if (visited[i]) continue;
        
        // Find the cycle starting at position i
        vi cycle;
        int curr = i;
        
        while (!visited[curr]) {
            visited[curr] = true;
            cycle.push_back(books[curr]);
            
            // Find where current book should go
            int target = target_pos[books[curr]];
            curr = target;
        }
        
        if (cycle.size() == 1) continue; // Already in correct position
        
        // Calculate cost for this cycle
        int cycle_min = *min_element(all(cycle));
        ll cycle_sum = 0;
        for (int val : cycle) cycle_sum += val;
        
        // Option 1: Use minimum within cycle
        // Cost = (sum of cycle) + (cycle_size - 2) * cycle_min
        ll cost1 = cycle_sum + (ll)(cycle.size() - 2) * cycle_min;
        
        // Option 2: Borrow global minimum
        // Cost = (sum of cycle) + cycle_min + (cycle_size + 1) * global_min
        ll cost2 = cycle_sum + cycle_min + (ll)(cycle.size() + 1) * global_min;
        
        total_cost += min(cost1, cost2);
    }
    
    cout << total_cost << endl;
    
    return 0;
}