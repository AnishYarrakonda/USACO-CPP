#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a; int b; int c; int d;
    cin >> a >> b; cin >> c >> d;
    
    int painted = 0;

    for (int i = 0; i < 100; i++) {
        if ((a <= i and i < b) || (c <= i and i < d)) painted += 1;
    }

    cout << painted << endl;

    return 0;
}