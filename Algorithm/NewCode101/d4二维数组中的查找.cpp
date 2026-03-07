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
     * @param target int整型
     * @param array int整型vector<vector<>>
     * @return bool布尔型
     */
    bool Find(int target, vector<vector<int>> &array)
    {
        if (array.empty())
            return false;

        // 二维化一维
        int m = array.size(), n = array[0].size();
        vector<int> nums(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                nums.push_back(array[m][n]);
        }

        int left = 0, right = nums.size();
        int mid = 0;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        if (nums[left] == target)
            return true;
        else
            return false;
    }
};