#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef long long ll;

bool haveNoIntersection(const set<char>& set1, const set<char>& set2) {
    vector<char> intersection;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(intersection));
    return intersection.empty();
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<set<char>> spotty(M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {char c; cin >> c; spotty[j].insert(c);}
    vector<set<char>> plain(M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {char c; cin >> c; plain[j].insert(c);}

    int count = 0;
    for (int i = 0; i < M; i++) if (haveNoIntersection(spotty[i], plain[i])) count++;

    cout << count << endl;

    return 0;
}