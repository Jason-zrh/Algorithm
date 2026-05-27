#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, right = 0, left = 0, n = s.size();
        for(right = 0; right < n; right++)
        {
            char c = s[right];
            // 入窗口
            mp[c]++;
            // 如果窗口右移导致非法，则左窗口收缩直到合法
            while(mp[c] > 1)
            {
                mp[s[left]]--;
                left++;
            }
            // 更新结果
            ans = max(ans, (right - left + 1));
        }
        return ans;
    }
};