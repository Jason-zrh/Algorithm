#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
     */
    string path;
    vector<string> ans;
    void dfs(string& str, vector<bool>& used)
    {
        // 长度满足直接返回
        if(path.length() == str.length())
        {
            ans.emplace_back(path);
            return;
        }
        // 内部递归条件
        for(int i = 0; i < str.length(); i++)
        {
            if(used[i] || (i > 0 && str[i] == str[i - 1] && !used[i - 1]))
                continue;
            path += str[i];
            used[i] = true;
            dfs(str, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<string> Permutation(string str)
    {
        vector<bool> used(str.length(), false);
        sort(str.begin(), str.end());
        dfs(str, used);
        return ans;
    }
};