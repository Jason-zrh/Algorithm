#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int ans = 0, n = s.size();
        int left = 0, right = 0;
        int window = 0;
        for (right = 0; right < n; right++)
        {
            // 入窗口
            char c = s[right];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                window++;
            // 窗口大小不够，直接进入下一次循环
            if(right - left + 1 < k)
                continue;
            // 窗口合法更新结果
            ans = max(ans, window);
            // 左指针移动破坏窗口
            c = s[left];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                window--;
            left++;
        }
        return ans;
    }
};