#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int x1, x2, x3, x4;
int y1, y2, y3, y4;

void update(int x, int y) {
    if (x < x1) {
        x2 = x1;
        x1 = x;
    } else if (x < x2) {
        x2 = x;
    }
    if (x > x4) {
        x3 = x4;
        x4 = x;
    } else if (x > x3) {
        x3 = x;
    }

    if (y < y1) {
        y2 = y1;
        y1 = y;
    } else if (y < y2) {
        y2 = y;
    }
    if (y > y4) {
        y3 = y4;
        y4 = y;
    } else if (y > y3) {
        y3 = y;
    }
}

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int n;
    fin >> n;

    x1 = INT_MAX;
    x2 = INT_MAX;
    x3 = 0;
    x4 = 0;
    y1 = INT_MAX;
    y2 = INT_MAX;
    y3 = 0;
    y4 = 0;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        update(x[i], y[i]);
    }

    int ans = (x4 - x1) * (y4 - y1);

    for (int i = 0; i < n; i++) {
        int xMin = x1;
        if (x[i] == xMin) {
            xMin = x2;
        }
        int xMax = x4;
        if (x[i] == xMax) {
            xMax = x3;
        }
        int yMin = y1;
        if (y[i] == yMin) {
            yMin = y2;
        }
        int yMax = y4;
        if (y[i] == yMax) {
            yMax = y3;
        }
        ans = min(ans, (xMax - xMin) * (yMax - yMin));
    }

    fout << ans << "\n";

    return 0;
}