#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        for(auto& str : strs)
        {
            string old = str;
            sort(str.begin(), str.end());
            strMap[str].push_back(old);
        }
        vector<vector<string>> ans;
        for(auto it = strMap.begin(); it != strMap.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main()
{
    return 0;
}