#include <stack>
#include <vector>
#include <iostream>

using namespace std;


// 明日再战···
string decodeString(string s)
{
    string ans;
    stack<char> match; // 存符号
    stack<char> letter; // 存字母
    

    int pos = 0;
    while(pos < s.size())
    {
        // 普通字母直接拼接到答案后面
        if(isalpha(s[pos]))
            ans.append(sizeof(s[pos]), s[pos]);

        // 数字, 压栈
        if(isdigit(s[pos]))
            match.push(s[pos]);
        
        // 检测到左括号，一直将后面是字母的入栈
        if(s[pos] == '[')
        {
            pos++;
            while (isalpha(s[pos]))
            {
                letter.push(s[pos]);
                pos++;
            }
            // 再给字母压一个0标识字母区间
            letter.push('0');
            continue;
        }

        // 处理一次拼接
        if(s[pos] == ']')
        {
            int mul = match.top() - '0';
            match.pop(); // 弹出重复次数
            string str;
            letter.pop(); // 弹出'0'
            while(!letter.empty() && isalpha(letter.top()) )
            {
                str.insert(str.begin(), letter.top());
                letter.pop();
            }
            for(int i = 0; i < mul; i++)
                ans.append(str);
        }
        pos++;
    }

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