#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
            
        unordered_map<char, int> cnt;
        int ans = 0;
        int left = 0, right = 0;
        for(right = 0; right < s.size(); right++)
        {
            char c = s[right];
            // 入窗口
            cnt[c]++;

            // 左侧出窗口维护答案
            while(cnt[c] > 1)
            {
                cnt[s[left]]--;
                left++;
            }

            // 找到一个
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};