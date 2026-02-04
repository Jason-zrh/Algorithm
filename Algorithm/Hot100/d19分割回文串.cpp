#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int n;
    vector<vector<string>> ans;
    vector<string> path;

    bool is_palindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

    // i位置代表在s[i]后面放不放逗号
    void dfs(const string &s, int i, int start)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }

        // 不分割
        if (i < n - 1)
        {
            dfs(s, i + 1, start);
        }

        // 分割
        if(is_palindrome(s, start, i))
        {
            path.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        n = s.size();
        dfs(s, 0, 0);
        return ans;
    }
};