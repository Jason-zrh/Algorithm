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
     * @param input int整型vector
     * @param k int整型
     * @return int整型vector
     */
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k)
    {
        vector<int> ans;
        sort(input.begin(), input.end());
        for(int i = 0; i < k; i++)
            ans.push_back(input[i]);
        return ans;
    }
};