#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    vector<string> ans;
    string path;
    void dfs(string& digits, int pos)
    {
        // 边界条件
        if(pos == digits.size())
        {
            ans.emplace_back(path);
            return;
        }

        // 非边界条件
        for(char ch : letters[digits[pos] - '0'])
        {
            // 添加一个答案
            path.push_back(ch);
            // 递归添加下一个位置
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int len = digits.size();
        if(len == 0)
            return {};
        
        dfs(digits, 0);
        return ans;
    }
};