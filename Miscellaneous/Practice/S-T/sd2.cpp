#include <iostream>
#include <fstream>
using namespace std;
 
int N, A[1000001]; // 1=healthy, -1=sick, 0=no cow
 
// Returns size of largest gap between a health and a sick cow
int find_smallest_01_gap(void)
{
  int smallest_gap = 2000000, current_start = -1;
  for (int i=0; i<=1000000; i++) 
    if (A[i] != 0) {
      if (current_start!=-1 && A[current_start]!=A[i] && i-current_start<smallest_gap) 
	smallest_gap = i-current_start;
      current_start = i;
    }
  return smallest_gap;
}
 
// Number of blocks of sick cows, delineated by healthy cows
int num_sick_clusters(void)
{
  int last_state = 0, answer = 0;
  for (int i=0; i<=1000000; i++) 
    if (A[i] != 0) {
      if (A[i] != last_state && A[i] == 1) answer++;
      last_state = A[i];
    }
  return answer;
}
 
// Number of gaps of size r or larger within blocks of sick cows
int num_sick_gaps(int r)
{
  int answer = 0, current_start = 0;
  for (int i=0; i<=1000000; i++) 
    if (A[i] != 0) {
      if (current_start!=0 && A[current_start]==1 && A[i]==1 && i-current_start>=r) 
	answer++;
      current_start = i;
    }
  return answer;
}
 
int main(void)
{
  ifstream fin ("socdist2.in");
  int x, s;
  fin >> N;
  for (int i=0; i<N; i++) {
    fin >> x >> s;
    if (s==1) { A[x] = 1; }
    if (s==0) { A[x] = -1; }
  }
  ofstream fout ("socdist2.out");
  int r = find_smallest_01_gap();
  fout << num_sick_clusters() + num_sick_gaps(r) << "\n";
  return 0;
}