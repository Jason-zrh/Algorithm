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
    string makeGood(string s) {
        stack<char> st;
        for(auto& c : s) {
            if(st.empty()) {
                st.push(c);
                continue;
            }
            if(st.top() + ('a' - 'A') == c || st.top() - ('a' - 'A') == c) {
                st.pop();
            }else {
                st.push(c);
            }
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

