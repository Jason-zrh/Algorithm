#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cntP(26, 0), cntS(26, 0);

        for(char c : p) 
            cntP[c - 'a']++;

        int k = p.size();
        int left = 0, right = 0;
        for(right = 0; right < s.size(); right++) {
            cntS[s[right] - 'a']++;

            if(right - left + 1< k)
                continue;

            // 比较
            if(cntS == cntP) {
                ans.push_back(left);
            }

            // 左侧出窗口
            cntS[s[left] - 'a']--;
            left++;
        }

        return ans;
    }
};