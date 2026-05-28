#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 对待合并的数组进行排序，从小到大排序
        sort(intervals.begin(), intervals.end(),\
        [](vector<int> a1, vector<int> a2)
             {
                if(a1[0] != a2[0])
                    return a1[0] < a2[0];
                else
                    return a1[1] < a2[1];
             }\
            );
        vector<vector<int>> ans;
        for (auto& p : intervals) 
        {
            // ans存在区间且可以合并，因为排序的原因，所以这里可以直接比较最后一个值与新数组的第一个值的大小
            if (!ans.empty() && p[0] <= ans.back()[1])
                ans.back()[1] = max(p[1], ans.back()[1]);
            else
                ans.emplace_back(p);
        }
        return ans;
    }
};