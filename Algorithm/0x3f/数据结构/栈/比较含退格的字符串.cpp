#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(auto& c : s) {
            if(c == '#') {
                if(!st1.empty()) {
                    st1.pop();
                }
            }else {
                st1.push(c);
            }
        }

        for(auto& c : t) {
            if(c == '#') {
                if(!st2.empty()) {
                    st2.pop();
                }
            }else {
                st2.push(c);
            }
        }
        return st1 == st2;
    }
};

