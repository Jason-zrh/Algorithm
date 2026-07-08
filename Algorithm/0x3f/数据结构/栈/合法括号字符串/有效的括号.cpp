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
    bool isValid(string s) {
        stack<char> st;
        for(auto& c : s) {
            if(st.empty()) {
                st.push(c);
                continue;
            }
            if(c == ')' && st.top() == '(') {
                st.pop();
                continue;
            }
            if(c == ']' && st.top() == '[') {
                st.pop();
                continue;
            }
            if(c == '}' && st.top() == '{') {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.empty();
    }
};