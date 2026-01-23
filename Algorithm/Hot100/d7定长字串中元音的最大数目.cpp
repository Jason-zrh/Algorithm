#include <string>
#include <algorithm>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        // 定长滑动窗口
        // 1:入窗口，如果r - k + 1 < 0 则还没形成第一个窗口，就继续重复第一步
        int left = 0;
        int ans = 0, cnt = 0;
        for(int right = 0; right < s.size(); right++)
        {
            // 1: 第一步入窗口
            if(s[right] == 'a' || s[right] == 'e' || 
               s[right] == 'i' || s[right] == 'o' || 
               s[right] == 'u')
                cnt++;
            
            left = right - k + 1;
            if(left < 0)
                continue;

            // 2: 更新答案
            ans = std::max(ans, cnt);

            // 3: 出窗口
            if(s[left] == 'a' || s[left] == 'e' || 
               s[left] == 'i' || s[left] == 'o' || 
               s[left] == 'u')
                cnt--;
        }
        return ans;
    }
};