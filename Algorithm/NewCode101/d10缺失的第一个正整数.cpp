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
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1;
        while (st.find(res) != st.end())
        {
            res++;
        }
        return res;
    }
};