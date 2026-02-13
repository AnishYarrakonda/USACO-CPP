#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define INF 1000000010

int main() {
  freopen("trapped.in", "r", stdin);
  freopen("trapped.out", "w", stdout);

  int N, B;
  cin >> N >> B;
  vector<pair<int, int> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].second >> A[i].first;
  }
  sort(A.begin(), A.end());

  int result = INF;
  int sp = lower_bound(A.begin(), A.end(), make_pair(B, 0)) - A.begin();

  int j = sp;
  for (int i = sp - 1; i >= 0; i--) {
    while (j < N && A[j].first <= A[i].first + A[i].second) {
      result = min(result, A[j].first - A[i].first - A[j].second);
      j++;
    }
  }

  j = sp - 1;
  for (int i = sp; i < N; i++) {
    while (j >= 0 && A[i].first - A[i].second <= A[j].first) {
      result = min(result, A[i].first - A[j].first - A[j].second);
      j--;
    }
  }

  if (result == INF) {
    cout << -1 << endl;
  } else {
    cout << max(result, 0) << endl;
  }
  return 0;
}