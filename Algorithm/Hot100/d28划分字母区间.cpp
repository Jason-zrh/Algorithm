#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        int last[26];
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i; // 每个字母最后出现的下标
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            end = max(end, last[s[i] - 'a']); // 更新当前区间右端点的最大值
            if (end == i)
            {                                   // 当前区间合并完毕
                ans.push_back(end - start + 1); // 区间长度加入答案
                start = i + 1;                  // 下一个区间的左端点
            }
        }
        return ans;
    }
};