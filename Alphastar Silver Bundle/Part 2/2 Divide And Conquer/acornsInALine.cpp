#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
int total_distance = 0;

void sortAcorns(vi &arr, int left, int right) {
    int len = right - left;
    if (len <= 1) return;

    int mid = left + len/2;

    // recursively sort left and right halves
    sortAcorns(arr, left, mid);
    sortAcorns(arr, mid, right);

    // compare lexicographically
    bool need_swap = false;
    for (int i = 0; i < len/2; i++) {
        if (arr[mid + i] < arr[left + i]) {
            need_swap = true;
            break;
        } else if (arr[mid + i] > arr[left + i]) {
            break;
        }
    }

    // if right half is smaller, swap them
    if (need_swap) {
        for (int i = 0; i < len/2; i++) {
            swap(arr[left + i], arr[mid + i]);
            total_distance += len/2; // each acorn moves len/2 positions
        }
    }
}

int main() {
    int N;
    cin >> N;
    int total = 1 << N; // 2^N acorns
    vi acorns(total);
    for (int i = 0; i < total; i++) cin >> acorns[i];

    sortAcorns(acorns, 0, total);

    cout << 2*total_distance << endl;
    for (int x : acorns) cout << x << endl;

    return 0;
}