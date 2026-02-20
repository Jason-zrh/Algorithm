#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> strMap;
        for(auto& str : strs)
        {
            string old = str;
            sort(str.begin(), str.end());
            strMap[str].push_back(old);
        }

        for(auto it = strMap.begin(); it != strMap.end(); it++)
            ans.push_back(it->second);

        return ans;
    }
};