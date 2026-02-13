#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int aux, int to) {
    if (n == 0) return;

    // Move n-1 disks from 'from' to 'aux'
    hanoi(n - 1, from, to, aux);

    // Move largest disk from 'from' to 'to'
    cout << from << " --> " << to << "\n";

    // Move n-1 disks from 'aux' to 'to'
    hanoi(n - 1, aux, from, to);
}

int main() {
    int N;
    cin >> N;

    // Move N disks from rod 1 to rod 3 using rod 2
    hanoi(N, 1, 2, 3);

    return 0;
}