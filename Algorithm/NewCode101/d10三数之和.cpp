#include <unordered_map>
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
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> ans;    
        sort(num.begin(), num.end());
        // 这里预留两个位置
        // 这里如果n不用int先保存的话会转到无符号int导致进入循环(cnm)
        int n = num.size();
        for(int i = 0; i < n - 2; i++)
        {
            // 还要判断i重不重复
            if(i && num[i] == num[i - 1])
                continue;

            int target = 0 - num[i];
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                if(num[j] + num[k] > target)
                    k--;
                else if(num[j] + num[k] < target)
                    j++;
                else
                {
                    // 找到相等的咯
                    ans.push_back({num[i], num[j], num[k]});
                    // 去重
                    ++j, --k;
                    while(j < k && num[j] == num[j - 1])
                        j++;
                    while(j < k && num[k] == num[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};