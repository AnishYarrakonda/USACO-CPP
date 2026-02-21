#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x;
    long long y;
};

struct Region {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    int side;
};

bool operator<(const Region& a, const Region& b) {
    if (a.x1 != b.x1) return a.x1 < b.x1;
    if (a.y1 != b.y1) return a.y1 < b.y1;
    if (a.x2 != b.x2) return a.x2 < b.x2;
    if (a.y2 != b.y2) return a.y2 < b.y2;
    return a.side < b.side;
}

bool same_region(const Region& a, const Region& b) {
    return a.x1 == b.x1 && a.y1 == b.y1 &&
           a.x2 == b.x2 && a.y2 == b.y2 &&
           a.side == b.side;
}

const long long DX[6] = {1, 0, -1, -1, 0, 1};
const long long DY[6] = {0, 1, 1, 0, -1, -1};

Point add_points(const Point& a, const Point& b) {
    Point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Point subtract_points(const Point& a, const Point& b) {
    Point result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Point direction_point(int i) {
    Point result;
    result.x = DX[i];
    result.y = DY[i];
    return result;
}

long long cross_product(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool point_less(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int direction_index(const Point& d) {
    for (int i = 0; i < 6; i++) {
        if (DX[i] == d.x && DY[i] == d.y) {
            return i;
        }
    }
    return -1;
}

Region make_region(Point p, Point q, Point third_vertex) {
    if (point_less(q, p)) {
        swap(p, q);
    }

    Point pq = subtract_points(q, p);
    Point pr = subtract_points(third_vertex, p);
    long long area_sign = cross_product(pq, pr);

    Region result;
    result.x1 = p.x;
    result.y1 = p.y;
    result.x2 = q.x;
    result.y2 = q.y;
    result.side = (area_sign > 0 ? 0 : 1);
    return result;
}

Point third_vertex_of_triangle(const Region& region) {
    Point a{region.x1, region.y1};
    Point b{region.x2, region.y2};
    Point edge = subtract_points(b, a);
    int index = direction_index(edge);

    Point third;
    if (region.side == 0) {
        third = add_points(a, direction_point((index + 1) % 6));
    } else {
        third = add_points(a, direction_point((index + 5) % 6));
    }
    return third;
}

void find_neighbors(const Region& current, Region next_regions[3]) {
    Point a{current.x1, current.y1};
    Point b{current.x2, current.y2};
    Point third = third_vertex_of_triangle(current);

    Region across_shared_edge = current;
    across_shared_edge.side = 1 - across_shared_edge.side;

    Region across_center_edge_1 = make_region(a, third, b);
    Region across_center_edge_2 = make_region(b, third, a);

    next_regions[0] = across_shared_edge;
    next_regions[1] = across_center_edge_1;
    next_regions[2] = across_center_edge_2;
}

Region region_from_input(long long x, long long y, int z) {
    Point v{x, y};
    int m = z / 2;

    Point p, q, r;
    if (z % 2 == 0) {
        p = v;
        q = add_points(v, direction_point(m));
        r = add_points(v, direction_point((m + 1) % 6));
    } else {
        p = v;
        q = add_points(v, direction_point((m + 1) % 6));
        r = add_points(v, direction_point(m));
    }

    return make_region(p, q, r);
}

int bfs_distance(const Region& start, const Region& target) {
    if (same_region(start, target)) {
        return 0;
    }

    map<Region, int> distance_from_start;
    queue<Region> q;

    distance_from_start[start] = 0;
    q.push(start);

    while (!q.empty()) {
        Region current = q.front();
        q.pop();

        int current_distance = distance_from_start[current];

        Region next_regions[3];
        find_neighbors(current, next_regions);

        for (int i = 0; i < 3; i++) {
            Region next_region = next_regions[i];

            if (distance_from_start.find(next_region) != distance_from_start.end()) {
                continue;
            }
            if (same_region(next_region, target)) {
                return current_distance + 1;
            }

            distance_from_start[next_region] = current_distance + 1;
            q.push(next_region);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Region> regions(N);

        for (int i = 0; i < N; i++) {
            long long x, y;
            int z;
            cin >> x >> y >> z;
            regions[i] = region_from_input(x, y, z);
        }

        long long answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                answer += bfs_distance(regions[i], regions[j]);
            }
        }

        cout << answer << '\n';
    }
    return 0;
}
