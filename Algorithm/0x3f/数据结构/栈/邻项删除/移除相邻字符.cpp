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
    string resultingString(string s) {
        stack<char> st;
        for(auto& c : s) {
            if(st.empty()) {
                st.push(c);
                continue;
            }
            if(abs(st.top() - c) % 26 == 1 || abs(st.top() - c) % 26 == 25) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

