#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length(), ans = 0, left = 0;
    unordered_map<char, int> cnt; // 维护从下标 left 到下标 right 的字符
    for (int right = 0; right < n; right++)
    {
        char c = s[right];
        cnt[c]++;
        while (cnt[c] > 1)
        {                   // 窗口内有重复字母
            cnt[s[left]]--; // 移除窗口左端点字母
            left++;         // 缩小窗口
        }
        ans = max(ans, right - left + 1); // 更新窗口长度最大值
    }
    return ans;
}
int main()
{
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}