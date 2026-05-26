#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int ans = 0, n = arrivals.size();
        int left = 0, right = 0;
        unordered_map<int, int> mp;

        for(right = 0; right < n; right++)
        {
            // 入窗口
            mp[arrivals[right]]++;
            // 判断需不需要丢弃
            if(mp[arrivals[right]] > m)
            {
                // 标记为0代表丢弃
                mp[arrivals[right]]--;
                arrivals[right] = 0;
                // 丢弃+1
                ans++;
            }
            // 窗口大小不够
            if(right - left + 1 < w)
                continue;
            // 左侧出窗口
            mp[arrivals[left]]--;
            left++;
        }
        return ans;
    }
};