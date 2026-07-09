#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;
        for(auto& c : s) {
            // 碰到一个括号收束
            if(c == ')') {
                string tmp = "";
                while(st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto& c : tmp) {
                    st.push(c);
                }
            }else {
                // 是左括号或者字母
                st.push(c);
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};