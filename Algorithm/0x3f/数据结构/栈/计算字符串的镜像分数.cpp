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
    char mirrorimage(char c) {
        return 'a' + 'z' - c;
    }

    long long calculateScore(string s) {
        long long ans = 0;
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            char c = mirrorimage(s[i]);
            if(!mp[c].empty()) {
                ans += i - mp[c][mp[c].size() - 1];
                mp[c].pop_back();
            }else {
                mp[s[i]].push_back(i);
            }
        }
        return ans;
    }
};