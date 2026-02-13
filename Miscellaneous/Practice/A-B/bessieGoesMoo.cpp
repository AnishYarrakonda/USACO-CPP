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
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);

    int N; cin >> N;
    unordered_map<char,vector<ll>> variables = {
        {'B', {0,0,0,0,0,0,0}}, {'E', {0,0,0,0,0,0,0}}, {'S', {0,0,0,0,0,0,0}},
        {'I', {0,0,0,0,0,0,0}}, {'G', {0,0,0,0,0,0,0}}, {'O', {0,0,0,0,0,0,0}},
        {'M', {0,0,0,0,0,0,0}}
    };

    for (int i = 0; i < N; i++) {
        char c; int val; cin >> c >> val;
        variables[c][(val%7+7)%7]++;
    }

    ll total = 0;

    for(int B = 0; B < 7; B++)
    for(int E = 0; E < 7; E++)
    for(int S = 0; S < 7; S++)
    for(int I = 0; I < 7; I++)
    for(int G = 0; G < 7; G++)
    for(int O = 0; O < 7; O++)
    for(int M = 0; M < 7; M++) {
        if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0) {
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