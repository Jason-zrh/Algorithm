#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        stk.push(-1); // 虚拟红线（哨兵）
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {                // 炸弹
                stk.push(i); // 记录炸弹下标
            }
            else if (stk.size() > 1)
            {                                  // 栈顶是炸弹
                stk.pop();                     // 拆弹
                ans = max(ans, i - stk.top()); // 右端点为 i 时，左端点最小是 stk.top() + 1
            }
            else
            {                  // 栈只有一个数，是红线，s[i] 无法拆弹，成为新的红线
                stk.top() = i; // 替换栈底
            }
        }
        return ans;
    }
};
