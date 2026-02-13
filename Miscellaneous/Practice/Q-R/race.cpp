#include <stdio.h>
 
int solve(int dist) {
  int minspeed;
  scanf("%d", &minspeed);
  int lhstravel = 0;
  int rhstravel = 0;
  int timeused = 0;
  for(int currspeed = 1;; currspeed++) {
    lhstravel += currspeed;
    timeused++;
    if(lhstravel + rhstravel >= dist) return timeused;
    if(currspeed >= minspeed) {
      rhstravel += currspeed;
      timeused++;
      if(lhstravel + rhstravel >= dist) return timeused;
    }
  }
}
 
int main() {
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  int k, n;
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; i++) {
    printf("%d\n", solve(k));
  }
}