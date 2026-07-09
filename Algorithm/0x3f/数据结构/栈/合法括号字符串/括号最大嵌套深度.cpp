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
    int maxDepth(string s) {
        int ans = 0, tmp = 0;
        for(auto& c : s) {
            if(c == '(') {
                tmp++;
            }else if(c == ')') {
                ans = max(ans, tmp);
                tmp--;
            }
        }
        return ans;
    }
};