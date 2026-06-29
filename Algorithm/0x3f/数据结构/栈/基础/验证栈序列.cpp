#include <stack>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index = 0;
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);

            while (!st.empty() && index < popped.size() && st.top() == popped[index]) {
                st.pop();
                index++;
            }
        }
        return st.empty();
    }
};

