#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string decodeString(string s)
{
    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ']')
        {
            stk.push(s[i]);
        }
        else
        {
            // 1. 获取括号内的字符串
            string str = "";
            while (!stk.empty() && stk.top() != '[')
            {
                str += stk.top();
                stk.pop();
            }
            stk.pop(); // 弹出 '['

            // 2. 获取倍数 (可能是多位数，如 100)
            string numStr = "";
            while (!stk.empty() && isdigit(stk.top()))
            {
                numStr += stk.top();
                stk.pop();
            }
            reverse(numStr.begin(), numStr.end());
            int mul = stoi(numStr);

            // 3. 构造重复字符串
            // 注意：之前的 str 是反向出来的，这里可以先反转回来
            reverse(str.begin(), str.end());
            string repeated = "";
            while (mul--)
            {
                repeated += str;
            }

            // 4. 将结果重新压入栈中供外层嵌套使用
            for (char c : repeated)
            {
                stk.push(c);
            }
        }
    }

    // 最终栈中剩下的就是解析后的结果
    string ans = "";
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // string str = "3[a]2[bc]";
    // string str = "3[a2[c]]";
    string str = "2[abc]3[cd]ef";
    cout << decodeString(str) << endl;
    return 0;
}