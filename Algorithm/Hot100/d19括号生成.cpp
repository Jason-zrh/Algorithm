#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<string> ans;
    string path;

    // left: 当前已使用的左括号数量，right: 当前已使用的右括号数量
    void dfs(int n, int left, int right) {
        // 1. 边界条件：左右括号都用完了
        if (path.size() == n * 2) {
            ans.push_back(path);
            return;
        }

        // 2. 尝试添加左括号：只要左括号还没满 n 个
        if (left < n) {
            path.push_back('(');
            dfs(n, left + 1, right);
            path.pop_back(); // 回溯
        }

        // 3. 尝试添加右括号：只要当前右括号比左括号少
        if (right < left) {
            path.push_back(')');
            dfs(n, left, right + 1);
            path.pop_back(); // 回溯
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};