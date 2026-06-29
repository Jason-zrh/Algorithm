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
    string removeStars(string s) {
        string ans = "";
        for(auto& c : s) {
            if(c != '*') {
                ans += c;
            }else {
                ans.erase(ans.size() - 1, 1);
            }
        }
        return ans;
    }
};

