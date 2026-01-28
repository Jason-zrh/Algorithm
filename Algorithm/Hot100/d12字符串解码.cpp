#include <stack>
#include <vector>
#include <iostream>

using namespace std;


// 明日再战···
string decodeString(string s)
{
    stack<char> stk;
    for(auto& c : s)
        stk.push(c);
    
    string ans;
    while(!stk.empty())
    {
        string str;
        // 右括号，则一直出栈直到出到数字
        if(stk.top() == ']')
        {
            // 右括号弹出
            stk.pop();
            // 将里面的字母全部弹出并头插到str中
            while(stk.top() != '[')
            {
                char ch = stk.top();
                stk.pop();
                str.insert(str.begin(), ch);
            }
            // 弹出左括号
            stk.pop(); 
            // 弹出复制次数
            int n = stk.top() - '0';
            stk.pop();
            // 将字符串复制n次
            string cp = str;
            for(int i = 0; i < n - 1; i++)
                str.insert(0, cp);
        }
        // 只是字母
        else
        {
            char ch = stk.top();
            str.insert(str.begin(), ch);
            stk.pop();
        }
        ans.insert(0, str);
    }
    return ans;
}

int main()
{
    string str = "3[a]2[bc]";
    cout << decodeString(str) << endl;
    return 0;
}