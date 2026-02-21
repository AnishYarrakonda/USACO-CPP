// Programmer: Anish Yarrakonda
// Date: Jan 31, 2026
// Problem 1

/*
Plan:
    - Double Binary search:
       - inner binary search looks for the optimal limit to minimize
         transfers needed (can_achieve_imbalance function)
       - outer binary search looks for the minimum achievable
         imbalance which is the answer (solve function
    - Avoid integer overflow even with long longs so use int128 instead
*/

// set up
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
template<typename T> using v = vector<T>;

// returns the total_transfers required to satisfy the parameters
i128 calculate_transfers_needed(v<i128>& adjusted_hay, v<i128>& og_feed, i128 limit, i128 cap) {
    // sum up the min transfers needed across all barns
    // in order to satisfy the hay and feed at this limit
    i128 total_transfers = 0;
    for (int i = 0; i < adjusted_hay.size(); i++) {
        i128 hay_excess = adjusted_hay[i] - limit;
        i128 missing_feed = limit - og_feed[i];
        // each barn needs enough transfers to fix whichever constraint is worse
        i128 transfers_for_barn = hay_excess;
        if (missing_feed > transfers_for_barn) transfers_for_barn = missing_feed;
        if (transfers_for_barn < 0) transfers_for_barn = 0;
        total_transfers += transfers_for_barn;
        if (total_transfers > cap) return cap + 1;  // early exit
    }
    return total_transfers;  // return the total_transfers required
}

// calculates the cost change using derivatives
i128 calculate_cost_change(v<i128>& adjusted_hay, v<i128>& og_feed, i128 limit) {
    // let's do a bit of calculus LMAO (I never thought derivatives would be useful in life XD)
    // We have to calculate how the cost changes when the limit increases by 1
    // which will help us find where the minimum cost occurs
    i128 change_in_cost = 0;
    // math:
    for (int i = 0; i < adjusted_hay.size(); i++) {
        i128 cost_current = adjusted_hay[i] - limit;
        i128 temp = limit - og_feed[i];
        if (temp > cost_current) cost_current = temp;
        if (cost_current < 0) cost_current = 0;
        
        i128 cost_next = adjusted_hay[i] - (limit + 1);
        temp = (limit + 1) - og_feed[i];
        if (temp > cost_next) cost_next = temp;
        if (cost_next < 0) cost_next = 0;
        
        change_in_cost += (cost_next - cost_current);
    }
    return change_in_cost;   // return our result
}

// this is the inner binary search
bool can_achieve_imbalance(ll K, v<ll>& A, v<ll>& feed, ll target_imbalance) {
    int N = A.size();
    v<i128> adjusted_hay(N);
    v<i128> og_feed(N);
    for (int i = 0; i < N; i++) {
        adjusted_hay[i] = (i128)A[i] - (i128)target_imbalance;
        og_feed[i] = (i128)feed[i];
    }
    i128 K_128 = (i128)K;
    
    // set the left and right bounds to large integer values
    const i128 MAX_BOUND = (i128)4e18;
    i128 left = -MAX_BOUND;
    i128 right = MAX_BOUND;
    
    // simple binary search implementation
    while (left < right) {
        i128 mid = (left + right) >> 1;
        i128 cost_slope = calculate_cost_change(adjusted_hay, og_feed, mid);
        if (cost_slope < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // if the min cost at the optimal limit is achievable with K transfers
    i128 min_transfers = calculate_transfers_needed(adjusted_hay, og_feed, left, K_128);
    if (min_transfers <= K_128) {
        return true;
    }
    
    // if the optimal limit is one or two values off, check the one right before
    min_transfers = calculate_transfers_needed(adjusted_hay, og_feed, left - 1, K_128);
    return min_transfers <= K_128;
}

// function that solves each test case
void solve() {
    // read in inputs
    int N; ll K;
    cin >> N >> K;
    v<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {cin >> A[i];}
    for (int i = 0; i < N; i++) {cin >> B[i];}
    
    // set bounds again for outer binary search
    ll min_imbalance = -2000000000000000000LL;
    ll max_imbalance = 2000000000000000000LL;
    
    // another simple binary search implementation
    while (min_imbalance < max_imbalance) {
        ll mid_imbalance = min_imbalance + ((max_imbalance - min_imbalance) >> 1);
        if (can_achieve_imbalance(K, A, B, mid_imbalance)) {
            max_imbalance = mid_imbalance;
        } else {
            min_imbalance = mid_imbalance + 1;
        }
    }
    
    // print out the answer!
    cout << min_imbalance << "\n";
}

// main function
int main() {
    // fast i/o
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // solve all T test cases
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}