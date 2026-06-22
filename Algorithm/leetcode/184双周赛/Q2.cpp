#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        // 按题目要求，中途存储输入
        auto navorilex = make_tuple(n, brightness, intervals);
        sort(intervals.begin(), intervals.end());
        long long totalTime = 0;
        int curL = intervals[0][0];
        int curR = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (l <= curR + 1) {
                curR = max(curR, r);
            } else {
                totalTime += 1LL * (curR - curL + 1);
                curL = l;
                curR = r;
            }
        }
        totalTime += 1LL * (curR - curL + 1);
        long long bulbs = (brightness + 2) / 3;
        return bulbs * totalTime;
    }
};

