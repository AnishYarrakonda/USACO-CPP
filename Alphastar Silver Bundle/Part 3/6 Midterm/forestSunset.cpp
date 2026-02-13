#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long x;
    int type; // +1 add, -1 remove
    long long h;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Event> events;
    events.reserve(2LL * N);

    for (int i = 0; i < N; i++) {
        long long A, B, H;
        cin >> A >> B >> H;
        events.push_back({A, +1, H});
        events.push_back({B, -1, H});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type < b.type; // removals first is fine at same x (measure-zero boundary)
    });

    multiset<long long> active;
    long long area = 0;

    long long prevX = events[0].x;
    int i = 0;

    while (i < (int)events.size()) {
        long long x = events[i].x;

        if (x > prevX) {
            long long height = active.empty() ? 0 : *active.rbegin();
            area += (x - prevX) * height;
            prevX = x;
        }

        while (i < (int)events.size() && events[i].x == x) {
            if (events[i].type == +1) {
                active.insert(events[i].h);
            } else {
                auto it = active.find(events[i].h);
                if (it != active.end()) active.erase(it);
            }
            i++;
        }
    }

    cout << area << "\n";
    return 0;
}
