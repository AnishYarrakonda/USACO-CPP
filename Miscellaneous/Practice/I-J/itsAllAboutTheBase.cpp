#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef vector<int> vint;
typedef long long ll;

int evaluate(const string& num, int base) {
  return (num[0] - '0') * base * base +
         (num[1] - '0') * base +
         (num[2] - '0');
}

int main() {
  freopen("whatbase.in", "r", stdin);
  freopen("whatbase.out", "w", stdout);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    string num_in_x, num_in_y;
    cin >> num_in_x >> num_in_y;

    int X = 10;
    int Y = 10;
    while (X <= 15000 && Y <= 15000) {
      int num_x = evaluate(num_in_x, X);
      int num_y = evaluate(num_in_y, Y);
      if (num_x < num_y) {
        X++;
      } else if (num_y < num_x) {
        Y++;
      } else {
        cout << X << ' ' << Y << '\n';
        break;
      }
    }
  }
  return 0;
}