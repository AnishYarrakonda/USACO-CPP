// Programmer: Anish Yarrakonda
// Date: Jan 31, 2026
// Problem 3

/*
Plan: Brute Force
    - Simultae farmers moving along the functional graph over time to mark unsafe nodes
        - Use backward DP (alive) to check if a node at a given time can survive to the end
        - Use backward DP (ways) to compute maximum number of rests from a given node at a given time
*/

// set up
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vv = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

// computes max rests for each start node
vi get_max_rests(int N,int max_time,const vi& adj,const vi& farmer_starts) {
    // sim farmer positioms over time
    vvb unsafe(max_time+1,vb(N+1,false));
    vi current_farmers = farmer_starts;
    for (int t = 0; t <= max_time; t++) {
        for (int f : current_farmers) unsafe[t][f]=true;
        if (t < max_time) {
            for (int i = 0; i < current_farmers.size(); i++) current_farmers[i]=adj[current_farmers[i]];
        }
    }

    // backward DP for alive nodes
    vvb alive(max_time+1,vb(N+1,false));
    for (int u = 1; u <= N; u++) if (!unsafe[max_time][u]) alive[max_time][u]=true;  // base case
    for (int t = max_time-1; t >= 0; t--) {
        for (int u = 1; u <= N; u++) {
            if (unsafe[t][u]) continue;  // cannot be alive if unsafe
            alive[t][u]=alive[t+1][u]||alive[t+1][adj[u]];  // rest or move
        }
    }

    // backward DP for rest times
    vv ways(max_time+1,vi(N+1,-1));
    for (int u = 1; u <= N; u++) if (alive[max_time][u]) ways[max_time][u]=0;  // base case
    for (int t = max_time-1; t >= 0; t--) {
        for (int u = 1; u <= N; u++) {
            if (!alive[t][u]) continue;
            int res=-1;
            int v1=adj[u];
            if (alive[t+1][v1]&&ways[t+1][v1]!=-1) res=max(res,ways[t+1][v1]);
            if (alive[t+1][u]&&ways[t+1][u]!=-1) res=max(res,ways[t+1][u]+1);
            ways[t][u]=res;
        }
    }

    // collect the results and return them
    vi final_result(N+1);
    for (int i = 1; i <= N; i++) final_result[i]=ways[0][i];
    return final_result;
}

// main function
int main() {
    // fast i/o
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read in inputs
    int N, F;
    cin >> N >> F;

    // adj list
    vi adj(N+1);
    for (int i = 1; i <= N; i++) cin >> adj[i];
    vi farmer_starts(F);
    for (int i = 0; i < F; i++) cin >> farmer_starts[i];

    // to detect infinite cycles, do this:
    int lowLim=2*N+50;
    int upperLim=3*N+50;

    // compute max rests for both
    vi res1=get_max_rests(N,lowLim,adj,farmer_starts);
    vi res2=get_max_rests(N,upperLim,adj,farmer_starts);

    // output results for the answers
    for (int i = 1; i <= N; i++) {
        if (res1[i]==-1) cout << -1 << '\n';           // cannot survive
        else if (res2[i]>res1[i]) cout << -2 << '\n';  // infinite rest cycle
        else cout << res1[i] << '\n';                  // max finite rests
    }

    return 0;
}