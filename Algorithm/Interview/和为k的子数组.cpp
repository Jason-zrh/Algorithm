#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        // 用来存储前缀和出现次数
        unordered_map<int, int> prefixcnt;
        int prefix = 0;
        int n = nums.size();
        // 这一行非常重要，需要保存0为1
        prefixcnt[0] = 1;
        for(int i = 0; i < n; i++)
        {
            // 计算到当前位置的前缀和
            prefix += nums[i];
            // 查找符合条件的前缀和的数量
            ans += prefixcnt[prefix - k];
            // 将当前计算出的前缀和加入计数
            prefixcnt[prefix]++;
        }
        return ans;
    }
};