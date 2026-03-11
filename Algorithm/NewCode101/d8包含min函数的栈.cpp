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
    void push(int value)
    {
        st1.push(value);
        if(stmin.empty() || value <= stmin.top())
            stmin.push(value);
    }
    void pop()
    {
        int val = st1.top();
        st1.pop();
        if(stmin.top() == val)
            stmin.pop();
    }
    int top()
    {
        return st1.top();
    }
    int min()
    {
        return stmin.top();
    }

private:
    stack<int> st1;
    stack<int> stmin;
};