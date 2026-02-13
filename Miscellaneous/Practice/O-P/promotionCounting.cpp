#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    vector<int> beforeAfter(8);
    int promoted = 0;

    for (int i = 0; i < 4; i++) {
        int x; int y;
        cin >> x >> y;
        beforeAfter[2*i] = x;
        beforeAfter[2*i+1] = y;
        promoted += y - x;
    }

    for (int i = 0; i < 3; i++) {
        promoted = beforeAfter[2*i] + promoted - beforeAfter[2*i+1];
        cout << promoted << endl;
    }
    
    return 0;
}