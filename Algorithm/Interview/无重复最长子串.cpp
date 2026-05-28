#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        unordered_map<char, int> cnt;
        int left = 0, right = 0;
        int n = s.length();
        for(right = 0; right < n; right++)
        {
            // 触发重复条件
            if(cnt[s[right]] == 1)
            {
                // 先更新结果
                len = max(len, right - left);
                // 左端点一直出直到窗口符合条件
                while(cnt[s[right]] == 1)
                {
                    cnt[s[left]]--;
                    left++;
                }
            }
            // 入窗口
            cnt[s[right]]++;
        }
        return max(len, right - left);
    }
};