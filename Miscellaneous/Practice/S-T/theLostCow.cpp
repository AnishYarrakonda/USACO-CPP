#include <fstream>
using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y;
    fin >> x >> y;

    int pos = x;
    int dist = 0;

    for (int k = 0; ; k++) {
        int step = 1 << k;
        int target;

        if (k % 2 == 0) {
            target = x + step;
        } else {
            target = x - step;
        }

        if ((pos <= y && y <= target) || (target <= y && y <= pos)) {
            dist += abs(y - pos);
            break;
        }

        dist += abs(target - pos);
        pos = target;
    }

    fout << dist << endl;
    return 0;
}
