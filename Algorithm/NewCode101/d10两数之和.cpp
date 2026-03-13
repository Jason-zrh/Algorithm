#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++)
        {
            int n = target - numbers[i];
            auto it = mp.find(n);
            if(it != mp.end())
            {
                ans.push_back(i + 1);
                ans.push_back(mp[n] + 1);
                break;
            }
            mp[numbers[i]] = i;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};