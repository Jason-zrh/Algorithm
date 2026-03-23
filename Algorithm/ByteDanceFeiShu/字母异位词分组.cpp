#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> strMap;
        for(auto& str : strs)
        {
            string tmp = str;
            // 将每个单词都进行排序
            sort(str.begin(), str.end());
            strMap[str].push_back(tmp);
        }

        for(auto it = strMap.begin(); it != strMap.end(); it++)
            ans.emplace_back(it->second);

        return ans;
    }
};