#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<pair<char, char>> ans;
        unordered_map<char, int> suffix;
        unordered_map<char, int> prefix;
        for(auto& c : s) {
            suffix[c]++;
        }
        suffix[s[0]]--;
        prefix[s[0]]++;

        for(int j = 1; j < s.size() - 1; j++) {
            suffix[s[j]]--;
            for(char c = 'a'; c <= 'z'; c++) {
                if(prefix[c] > 0 && suffix[c] > 0) {
                    ans.insert(make_pair(c, s[j]));
                }
            }
            prefix[s[j]]++;
        }
        return ans.size();
    }
};

