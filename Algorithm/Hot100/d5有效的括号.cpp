#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for(auto& e : s)
    {
        if(st.empty())
            st.push(e);
        else
        {
            if(st.top() == '(' && e == ')')
            {
                st.pop();
                continue;
            }
            if(st.top() == '[' && e == ']')
            {
                st.pop();
                continue;
            }
            if(st.top() == '{' && e == '}')
            {
                st.pop();
                continue;
            }
            st.push(e);
        }
    }
    return st.empty();
}

int main()
{
   
    return 0;
}