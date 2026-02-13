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
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int N; cin >> N;
    vint B(N-1); for (int i = 0; i < N-1; i++) cin >> B[i];

    for (int a = 1; a <= N; a++) {
        unordered_set<int> used = {a};
        vint perm = {a};

        int i = 0;
        int prev = a;

        bool flag = false;
        while (i < N-1) {
            int b = B[i] - prev;
            if (used.count(b) || b <= 0 || b > N) {
                flag = true;
                break;
            }
            used.insert(b);
            perm.push_back(b);
            prev = b;
            i++;
        }
        
        if (flag) continue;
        else {
            for (int i = 0; i < N-1; i++) {
                cout << perm[i] << " ";
            }
            cout << perm.back();
            break;
        }
    }

    return 0;
}