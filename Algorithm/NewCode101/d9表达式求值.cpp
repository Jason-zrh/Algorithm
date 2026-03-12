#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 定义运算符优先级
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}};

void calculate(stack<int> &num, stack<char> &op)
{
    if (num.size() < 2 || op.empty())
        return;
    int right = num.top();
    num.pop();
    int left = num.top();
    num.pop();
    char c = op.top();
    op.pop();

    if (c == '+')
        num.push(left + right);
    else if (c == '-')
        num.push(left - right);
    else if (c == '*')
        num.push(left * right);
}

int solve(string s)
{
    stack<int> num;
    stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // 1. 处理多位数
        if (isdigit(c))
        {
            int val = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                val = val * 10 + (s[i++] - '0');
            }
            num.push(val);
            i--; // 抵消 for 循环的 i++
        }
        // 2. 左括号直接入栈
        else if (c == '(')
        {
            op.push(c);
        }
        // 3. 右括号触发计算直到遇到左括号
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                calculate(num, op);
            }
            op.pop(); // 弹出 '('
        }
        // 4. 处理运算符 (+, -, *)
        else
        {
            // 只要栈顶运算符优先级 >= 当前运算符，就先算栈顶的
            // 注意：左括号在栈中优先级最低，不参与此逻辑
            while (!op.empty() && op.top() != '(' && pr[op.top()] >= pr[c])
                calculate(num, op);
            
            op.push(c);
        }
    }

    // 最后清空符号栈
    while (!op.empty())
        calculate(num, op);
    return num.top();
}