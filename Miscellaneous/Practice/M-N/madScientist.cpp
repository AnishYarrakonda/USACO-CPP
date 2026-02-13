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
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N; cin >> N;
    string correct, wrong;
    cin >> correct;
    cin >> wrong;

    vector<bool> x = {correct[0] == wrong[0]};
    for (int i = 0; i < N; i++) {
        bool b = correct[i] == wrong[i];
        if (x.back() != b) x.push_back(b);
    }

    cout << count(x.begin(), x.end(), false) << '\n';

    return 0;
}