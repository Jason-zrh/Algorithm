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
            if(c == 'c' && st.top() == 'b') {
                st.pop();
                if(!st.empty() && st.top() == 'a') {
                    st.pop();
                }else {
                    st.push('b');
                    st.push(c);
                }
                continue;
            }
            st.push(c);
        }
        return st.empty();
    }
};