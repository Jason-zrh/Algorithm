#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int cur_right = 0;  // 已建造的桥的右端点
        int next_right = 0; // 下一座桥的右端点的最大值
        for (int i = 0; i + 1 < nums.size(); i++)
        {
            // 遍历的过程中，记录下一座桥的最远点
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right)
            {                           // 无路可走，必须建桥
                cur_right = next_right; // 建桥后，最远可以到达 next_right
                ans++;
            }
        }
        return ans;
    }
};