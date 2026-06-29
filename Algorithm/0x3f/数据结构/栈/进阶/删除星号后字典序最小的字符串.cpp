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
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> pos(26);
        vector<bool> removed(n, false);
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pos[s[i] - 'a'].push_back(i);
            } else {
                removed[i] = true;
                for (int c = 0; c < 26; c++) {
                    if (!pos[c].empty()) {
                        int idx = pos[c].back(); // 删除最靠右的最小字符
                        pos[c].pop_back();
                        removed[idx] = true;
                        break;
                    }
                }
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};

