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
    int stringToint(string str) {
        int mul = str.size() - 1;
        int flag = 1;
        if(str[0] == '-') {
            mul--;
            flag = -1;
        }
        int ans = 0;
        for(auto& c : str) {
            if(c == '-') {
                continue;
            }
            int num = c - '0';
            ans += num * (pow(10, mul));
            mul--;
        }
        return ans * flag;
    }

    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for(auto& c : operations) {
            if(c == "+") {
                // + 
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first);
                st.push(second);
                ans += first + second;
                st.push(first + second);
            }else if (c == "D"){
                // double
                ans += st.top() * 2;
                st.push(st.top() * 2);
            }else if (c == "C") {
                // 无效
                ans -= st.top();
                st.pop();
            }else {
                // 数字
                int num = stringToint(c);
                ans += num;
                st.push(num);
            }
            cout << ans << endl;
        }
        return ans;
    }
};