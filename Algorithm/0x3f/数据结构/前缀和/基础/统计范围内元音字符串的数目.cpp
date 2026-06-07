#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isAlpha(string& str) {
        char start = str.front();
        char end = str.back();
        if((start == 'a' || start == 'e' || start == 'i' || start == 'o' || start == 'u') && 
           (end == 'a' || end == 'e' || end == 'i' || end == 'o' || end == 'u')) {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefix(words.size() + 1, 0);
        for(int i = 1; i <= words.size(); i++) {
            if(isAlpha(words[i - 1])) {
                prefix[i] = prefix[i - 1] + 1;
            }else {
                prefix[i] = prefix[i - 1];
            }
        }
        for(int i = 0; i < queries.size(); i++) {
            ans.emplace_back(prefix[queries[i][1] + 1] - prefix[queries[i][0]]);
        }
        return ans;
    }
};