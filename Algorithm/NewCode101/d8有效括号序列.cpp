#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &c : s)
        {
            // 栈为空
            if (st.empty())
            {   
                st.push(c);
                continue;;
            }
            // 栈非空
            if (c == '{' || c == '(' || c == '[')
            {
                st.push(c);
                continue;;
            }

            if (c == '}' && st.top() == '{')
            {
                st.pop();
                continue;
            }

            if (c == ')' && st.top() == '(')
            {
                st.pop();
                continue;
            }

            if (c == ']' && st.top() == '[')
            {
                st.pop();
                continue;
            }
        }
        return st.empty();
    }
};