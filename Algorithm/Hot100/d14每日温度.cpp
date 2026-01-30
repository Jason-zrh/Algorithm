#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> stk; // 只需要存下标即可，值可以通过 temperatures[stk.top()] 获取

    for (int i = 0; i < n; i++)
    {
        // 只要当前温度大于栈顶温度，说明找到了栈顶元素“之后第一个更高温”
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
        {
            int prevIndex = stk.top();
            stk.pop();
            // 核心关键：天数差 = 当前下标 - 栈顶下标
            ans[prevIndex] = i - prevIndex;
        }
        // 每个下标都会入栈一次
        stk.push(i);
    }
    return ans;
}

int main()
{
    vector<int> ans;
    vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};
    ans = dailyTemperatures(nums);
    for (auto &e : ans)
        cout << e << " ";
    cout << endl;
    return 0;
}