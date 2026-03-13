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
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto& e : nums)
            mp[e]++;
        
        auto it = mp.begin();
        while(it != mp.end())
        {
            if(it->second == 1)
                ans.push_back(it->first);
            it++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};