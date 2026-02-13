#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef long long ll;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N; cin >> N;
    string mailboxes; cin >> mailboxes;

    int ans = N;
    for (int i = 1; i < N+1; i++) {
        unordered_set<string> positions;
        bool flag = true;
        for (int j = 0; j < N-i+1; j++) {
            string s = mailboxes.substr(j, i);
            if (positions.count(s)) {
                flag = false;
                break;
            }
            positions.insert(s);
        }
        if (flag) {
            cout << i << endl;
            break;
        }

    }
    return 0;
}