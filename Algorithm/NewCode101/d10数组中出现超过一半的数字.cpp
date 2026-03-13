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
     * @param numbers int整型vector
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int> &numbers)
    {
        int n = numbers.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto& e : numbers)
        {
            mp[e]++;
            if(mp[e] > (n / 2))
            {
                ans = e;
                break;
            }
        }
        return ans;
    }
};