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
    freopen("geteven.in", "r", stdin);
    freopen("geteven.out", "w", stdout);

    int N; cin >> N;
    unordered_map<char,vint> variables = {
        {'B', {0,0}}, {'E', {0,0}}, {'S', {0,0}},
        {'I', {0,0}}, {'G', {0,0}}, {'O', {0,0}},
        {'M', {0,0}}
    };

    for (int i = 0; i < N; i++) {
        char c; int val; cin >> c >> val;
        if (val % 2) variables[c][1] += 1;
        else variables[c][0] += 1;
    }

    int total = 0;

    for(int B = 0; B < 2; B++)
    for(int E = 0; E < 2; E++)
    for(int S = 0; S < 2; S++)
    for(int I = 0; I < 2; I++)
    for(int G = 0; G < 2; G++)
    for(int O = 0; O < 2; O++)
    for(int M = 0; M < 2; M++) {
        if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 2 == 0) {
            total +=    variables['B'][B] *
                        variables['E'][E] *
                        variables['S'][S] *
                        variables['I'][I] *
                        variables['G'][G] *
                        variables['O'][O] *
                        variables['M'][M];
        }
    }

    cout << total << endl;

    return 0;
}