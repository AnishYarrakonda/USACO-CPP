#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int minX = 10; int maxX = 0;
    int minY = 10; int maxY = 0;
    for (int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        minX = min({minX, x1, x2}); maxX = max({maxX, x1, x2});
        minY = min({minY, y1, y2}); maxY = max({maxY, y1, y2});
    }
    cout << pow(max(maxX-minX, maxY-minY), 2);
}