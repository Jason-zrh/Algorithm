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
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        int index = 0;
        for(auto& v : nums) {
            if(index % 2 != 0) {
                if(!st.empty() && st.top() == v) {
                    ans++;
                }else {
                    st.push(v);
                    index++;
                }
            }else {
                st.push(v);
                index++;
            }
        }
        if(st.size() % 2 != 0) {
            ans++;
        }
        return ans;
    }
};