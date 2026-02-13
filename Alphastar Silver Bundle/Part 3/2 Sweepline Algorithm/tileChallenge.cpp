#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x1, x2, y1, y2, id;
};

struct Event {
    int x, type, id;
};

struct Cmp {
    bool operator()(const Rect* a, const Rect* b) const {
        if (a->y1 != b->y1) return a->y1 < b->y1;
        return a->id < b->id;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int h = K / 2;

    vector<Rect> rects(N);
    vector<Event> events;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        rects[i] = {
            x - h, x + h,
            y - h, y + h,
            i
        };

        events.push_back({rects[i].x1, +1, i});
        events.push_back({rects[i].x2, -1, i});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type > b.type; // START before END
    });

    set<const Rect*, Cmp> active;

    int overlap_count = 0;
    pair<int,int> ans_pair = {-1, -1};

    for (auto& e : events) {
        const Rect* cur = &rects[e.id];

        if (e.type == +1) {
            auto it = active.lower_bound(cur);

            auto check = [&](const Rect* other) {
                // Check BOTH x and y overlap (positive area)
                if (min(cur->x2, other->x2) > max(cur->x1, other->x1) &&
                    min(cur->y2, other->y2) > max(cur->y1, other->y1)) {

                    overlap_count++;
                    ans_pair = {cur->id, other->id};
                    if (overlap_count > 1) {
                        cout << -1 << "\n";
                        exit(0);
                    }
                }
            };

            if (it != active.end())
                check(*it);

            if (it != active.begin()) {
                auto prev = it; --prev;
                check(*prev);
            }

            active.insert(cur);
        } else {
            active.erase(cur);
        }
    }

    if (overlap_count == 0) {
        cout << 0 << "\n";
        return 0;
    }

    Rect& A = rects[ans_pair.first];
    Rect& B = rects[ans_pair.second];

    int area =
        (min(A.x2, B.x2) - max(A.x1, B.x1)) *
        (min(A.y2, B.y2) - max(A.y1, B.y1));

    cout << area << "\n";
}