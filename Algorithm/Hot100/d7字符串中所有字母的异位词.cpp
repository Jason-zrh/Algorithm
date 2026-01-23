#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <array>

using namespace std;

// 不定长滑动窗口
// vector<int> findAnagrams(string s, string p)
// {
//     vector<int> ans;
//     // 这个题的窗口符合两个条件
//     // 条件1: 窗口内元素个数与p大小相等
//     // 条件2: 窗口中的元素与p相同
//     unordered_map<char, int> cnt;
//     // 将目标字母出现次数储存
//     for(auto& c : p)
//         cnt[c]++;
//     // p中字母个数
//     int psize = p.length();
//     int left = 0;
//     for(int right = 0; right < s.length(); right++)
//     {
//         char ch = s[right];
//         cnt[ch]--;
//         while(cnt[ch] < 0) // ch太多了，则将left向右移动
//         {
//             cnt[s[left]]++;
//             left++;
//         }
//         if(right - left + 1 == psize)
//             ans.push_back(left);
//     }
//     return ans;
// }

// 定长滑动窗口

vector<int> findAnagrams(string s, string p)
{
    array<int, 26> cnt_p{};
    for (auto &c : p)
        cnt_p[c - 'a']++;
    vector<int> ans;
    array<int, 26> cnt_s{};
    for (int right = 0; right < s.size(); right++)
    {
        // 1.入窗口
        cnt_s[s[right] - 'a']++;
        int left = right - p.size() + 1;
        if (left < 0)
            continue;

        // 更新结果
        if (cnt_s == cnt_p)
            ans.push_back(left);

        cnt_s[s[left] - 'a']--;
    }
    return ans;
}

int main()
{
    vector<int> res = findAnagrams("cbaebabacd", "abc");
    for (auto &e : res)
        cout << e << " ";
    cout << endl;
    return 0;
}