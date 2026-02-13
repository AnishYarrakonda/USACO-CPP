/*
Programmer: Anish Yarrakonda
Date: Jan 30
Problem 1
(-_-) MOST LOCKED IN!!!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input/output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read in N
    int N;
    cin >> N;

    // read in the array
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // count the distinct vluaes in the array
    int distinctCount = 0;
    vector<int> hasSeen(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (!hasSeen[A[i]]) {
            hasSeen[A[i]] = 1;
            distinctCount++;
        }
    }

    // double the array to handle the circle
    // this way if we travers eto the left and right, we will not exit the boudns of the vector
    vector<int> doubledA(2 * N + 2);
    for (int i = 1; i <= 2 * N; i++) {
        doubledA[i] = A[(i - 1) % N + 1];
    }

    // use a simple sliding window algorithm to find the minimum right endpoint
    const int invalidPos = 2 * N + 1;
    vector<int> rightEnd(2 * N + 2, invalidPos);
    vector<int> freqCount(N + 1, 0);

    int activeDistinct = 0;
    int rightPtr = 0;

    for (int leftPtr = 1; leftPtr <= 2 * N; leftPtr++) {
        while (
            rightPtr + 1 <= min(2 * N, leftPtr + N - 1) &&
            activeDistinct < distinctCount
        ) {
            rightPtr++;
            if (freqCount[doubledA[rightPtr]]++ == 0) {
                activeDistinct++;
            }
        }

        if (activeDistinct == distinctCount) {
            rightEnd[leftPtr] = rightPtr;
        }

        if (--freqCount[doubledA[leftPtr]] == 0) {
            activeDistinct--;
        }
    }

    // run a sweepline on the intervals we generated to identify the corrections
    vector<pair<int, long long>> addOneEvents, removeOneEvents;
    vector<pair<int, long long>> addTwoEvents, removeTwoEvents;
    vector<pair<int, long long>> addThreeEvents, removeThreeEvents;

    addOneEvents.reserve(2 * N);
    removeOneEvents.reserve(2 * N);
    addTwoEvents.reserve(2 * N);
    removeTwoEvents.reserve(2 * N);
    addThreeEvents.reserve(2 * N);
    removeThreeEvents.reserve(2 * N);

    for (int leftPtr = 1; leftPtr <= 2 * N; leftPtr++) {
        if (rightEnd[leftPtr] <= 2 * N) {
            long long rightPos = rightEnd[leftPtr];

            long long offsetOne = rightPos - 2LL * leftPtr;
            long long offsetTwo = 2LL * rightPos - leftPtr;

            addOneEvents.emplace_back(leftPtr, offsetOne);
            removeOneEvents.emplace_back((int)rightPos + 1, offsetOne);

            addTwoEvents.emplace_back(leftPtr, offsetTwo);
            removeTwoEvents.emplace_back((int)rightPos + 1, offsetTwo);

            int startPos = (int)rightPos + 1;
            int endPos = min(2 * N, leftPtr + N - 1);

            if (startPos <= endPos) {
                long long offsetThree = -1LL * leftPtr;
                addThreeEvents.emplace_back(startPos, offsetThree);
                removeThreeEvents.emplace_back(endPos + 1, offsetThree);
            }
        }
    }

    priority_queue<long long, vector<long long>, greater<long long>> pqOne, pqTwo, pqThree;
    unordered_map<long long, int> lazyDelOne, lazyDelTwo, lazyDelThree;

    const long long INF = (1LL << 60);
    vector<long long> bestVal(2 * N + 2, INF);

    size_t addIdxOne = 0, remIdxOne = 0;
    size_t addIdxTwo = 0, remIdxTwo = 0;
    size_t addIdxThree = 0, remIdxThree = 0;

    for (int pos = 1; pos <= 2 * N; pos++) {
        while (addIdxOne < addOneEvents.size() && addOneEvents[addIdxOne].first == pos) {
            pqOne.push(addOneEvents[addIdxOne].second);
            addIdxOne++;
        }
        while (addIdxTwo < addTwoEvents.size() && addTwoEvents[addIdxTwo].first == pos) {
            pqTwo.push(addTwoEvents[addIdxTwo].second);
            addIdxTwo++;
        }
        while (addIdxThree < addThreeEvents.size() && addThreeEvents[addIdxThree].first == pos) {
            pqThree.push(addThreeEvents[addIdxThree].second);
            addIdxThree++;
        }

        while (remIdxOne < removeOneEvents.size() && removeOneEvents[remIdxOne].first == pos) {
            lazyDelOne[removeOneEvents[remIdxOne].second]++;
            remIdxOne++;
        }
        while (remIdxTwo < removeTwoEvents.size() && removeTwoEvents[remIdxTwo].first == pos) {
            lazyDelTwo[removeTwoEvents[remIdxTwo].second]++;
            remIdxTwo++;
        }
        while (remIdxThree < removeThreeEvents.size() && removeThreeEvents[remIdxThree].first == pos) {
            lazyDelThree[removeThreeEvents[remIdxThree].second]++;
            remIdxThree++;
        }

        while (!pqOne.empty()) {
            long long val = pqOne.top();
            auto it = lazyDelOne.find(val);
            if (it != lazyDelOne.end() && it->second > 0) {
                pqOne.pop();
                if (--it->second == 0) lazyDelOne.erase(it);
            } else break;
        }

        while (!pqTwo.empty()) {
            long long val = pqTwo.top();
            auto it = lazyDelTwo.find(val);
            if (it != lazyDelTwo.end() && it->second > 0) {
                pqTwo.pop();
                if (--it->second == 0) lazyDelTwo.erase(it);
            } else break;
        }

        while (!pqThree.empty()) {
            long long val = pqThree.top();
            auto it = lazyDelThree.find(val);
            if (it != lazyDelThree.end() && it->second > 0) {
                pqThree.pop();
                if (--it->second == 0) lazyDelThree.erase(it);
            } else break;
        }

        long long bestHere = INF;
        if (!pqOne.empty()) bestHere = min(bestHere, (long long)pos + pqOne.top());
        if (!pqTwo.empty()) bestHere = min(bestHere, -(long long)pos + pqTwo.top());
        if (!pqThree.empty()) bestHere = min(bestHere, (long long)pos + pqThree.top());

        bestVal[pos] = bestHere;
    }

    for (int j = 1; j <= N; j++) {
        long long answer = min(bestVal[j], bestVal[j + N]);
        if (answer >= INF / 2) answer = -1;
        cout << answer << (j == N ? '\n' : ' ');
    }

    return 0;
}