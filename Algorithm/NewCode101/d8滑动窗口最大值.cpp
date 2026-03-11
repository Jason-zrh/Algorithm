#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型vector
     * @param size int整型
     * @return int整型vector
     */
    vector<int> maxInWindows(vector<int> &num, int size)
    {
        //维护一个双端队列，如果进来一个值大于前面的有的值，就可以把前面的都去掉
        deque<pair<int, int>> dq; // 左边下标，右边值
        vector<int> ans;

        int left = 0, right = 0;
        // 定长滑动窗口
        for(int right = 0; right < num.size(); right++)
        {
            // 入窗口的值
            int val = num[right];
            // 去掉值比val小的
            while(!dq.empty() && dq.back().second <= val)
                dq.pop_back();
            // 插入最大，此时dq的最右侧就是窗口的最大值
            dq.push_back(make_pair(right, val));
            // 窗口太小
            if(right - left + 1 < size)
                continue;
            // 窗口大小正好，更新答案
            ans.push_back(dq.front().second);
            // 左指针右移，破坏窗口 - 裁掉老员工
            if(dq.front().first == left)
                dq.pop_front();
            left++;
        }
        return ans;
    }
};