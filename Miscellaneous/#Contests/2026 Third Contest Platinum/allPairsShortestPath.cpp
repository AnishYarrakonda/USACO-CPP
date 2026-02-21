#include <bits/stdc++.h>
using namespace std;

struct GridPoint{
    long long x;
    long long y;
};

struct TriangleCell {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    int side;
};

bool operator<(const TriangleCell& a, const TriangleCell& b) {
    if (a.x1 != b.x1) return a.x1 < b.x1;
    if (a.y1 != b.y1) return a.y1 < b.y1;
    if (a.x2 != b.x2) return a.x2 < b.x2;
    if (a.y2 != b.y2) return a.y2 < b.y2;
    return a.side < b.side;
}

bool isSameCell(const TriangleCell& a, const TriangleCell& b){
    return a.x1 == b.x1 && a.y1 == b.y1
        && a.x2 == b.x2 && a.y2 == b.y2
        && a.side == b.side;
}

const long long stepX[6] = {1, 0, -1, -1, 0, 1};
const long long stepY[6] = {0, 1, 1, 0, -1, -1};

GridPoint addPoints(const GridPoint& a,const GridPoint& b) {
    GridPoint out;
    out.x = a.x + b.x;
    out.y = a.y + b.y;
    return out;
}

GridPoint subPoints(const GridPoint& a, const GridPoint& b) {
    GridPoint out;
    out.x = a.x - b.x;
    out.y = a.y - b.y;
    return out;
}

GridPoint dirAsPoint(int dirId){
    GridPoint out;
    out.x = stepX[dirId];
    out.y = stepY[dirId];
    return out;
}

long long cross2D(const GridPoint& a, const GridPoint& b){
    return a.x * b.y - a.y * b.x;
}

bool isEarlierPoint(const GridPoint& a, const GridPoint& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int findDirIndex(const GridPoint& v){
    for (int i = 0; i < 6; i++) {
        if (stepX[i] == v.x && stepY[i] == v.y) {
            return i;
        }
    }
    return -1;
}

TriangleCell makeCell(GridPoint p, GridPoint q, GridPoint third) {
    if (isEarlierPoint(q, p)) {
        swap(p, q);
    }

    GridPoint pq = subPoints(q, p);
    GridPoint pr = subPoints(third, p);
    long long signedArea = cross2D(pq, pr);

    TriangleCell out;
    out.x1 = p.x;
    out.y1 = p.y;
    out.x2 = q.x;
    out.y2 = q.y;
    out.side = (signedArea > 0 ? 0 : 1);
    return out;
}

GridPoint getThirdCorner(const TriangleCell& cell){
    GridPoint a{cell.x1, cell.y1};
    GridPoint b{cell.x2, cell.y2};
    GridPoint edgeVec = subPoints(b, a);
    int dirId = findDirIndex(edgeVec);

    GridPoint third;
    if (cell.side == 0) {
        third = addPoints(a, dirAsPoint((dirId + 1) % 6));
    } else {
      third = addPoints(a, dirAsPoint((dirId + 5) % 6));
    }
    return third;
}

void gatherNeighbors(const TriangleCell& curCell, TriangleCell nextCells[3]) {
    GridPoint a{curCell.x1, curCell.y1};
    GridPoint b{curCell.x2, curCell.y2};
    GridPoint third = getThirdCorner(curCell);

    TriangleCell flipSide = curCell;
    flipSide.side = 1 - flipSide.side;

    TriangleCell viaCenterA = makeCell(a, third, b);
    TriangleCell viaCenterB = makeCell(b, third, a);

    nextCells[0] = flipSide;
    nextCells[1] = viaCenterA;
    nextCells[2] = viaCenterB;
}

TriangleCell inputToCell(long long x, long long y, int z) {
    GridPoint base{x, y};
    int wedge = z / 2;

    GridPoint p, q, r;
    if (!(z & 1)){
        p = base;
        q = addPoints(base, dirAsPoint(wedge));
        r = addPoints(base, dirAsPoint((wedge + 1) % 6));
    } else {
        p = base;
        q = addPoints(base, dirAsPoint((wedge + 1) % 6));
        r = addPoints(base, dirAsPoint(wedge));
    }

    return makeCell(p, q, r);
}

int bfsDistanceBetween(const TriangleCell& startCell, const TriangleCell& goalCell){
    if (isSameCell(startCell, goalCell)) {
        return 0;
    }

    map<TriangleCell, int> dist;
    queue<TriangleCell> q;

    dist[startCell] = 0;
    q.push(startCell);

    while (!q.empty()) {
        TriangleCell cur = q.front();
        q.pop();

        int curDist = dist[cur];
        TriangleCell nextCells[3];
        gatherNeighbors(cur, nextCells);

        for (int i = 0; i < 3; i++) {
            TriangleCell nxt = nextCells[i];

            if (dist.find(nxt) != dist.end()) {
                continue;
            }
            if (isSameCell(nxt, goalCell)) {
                return curDist + 1;
            }

            dist[nxt] = curDist + 1;
            q.push(nxt);
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<TriangleCell> cells(n);

        for (int i = 0; i < n; i++) {
            long long x, y; int z;
            cin >> x >> y >> z;
            cells[i] = inputToCell(x, y, z);
        }

        long long pairSum = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) pairSum += bfsDistanceBetween(cells[i], cells[j]);
        cout << pairSum << '\n';
    }
    return 0;
}
