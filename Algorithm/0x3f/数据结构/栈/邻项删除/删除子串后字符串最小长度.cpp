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
    int minLength(string s) {
        stack<char> st;
        for(auto& c : s) {
            if(st.empty()) {
                st.push(c);
            } else {
                if((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D')) {
                    st.pop();
                    continue;
                }
                st.push(c);
            }
        }
        return st.size();
    }
};