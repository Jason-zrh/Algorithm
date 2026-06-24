#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<int> prefix(array.size() + 1, 0);
        for (int i = 0; i < array.size(); ++i) {
            prefix[i + 1] = prefix[i] + (array[i][0] >> 6 & 1) * 2 - 1;
        }
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        for(int i = 0; i <= array.size(); i++) {
            if(mp.find(prefix[i]) != mp.end()) {
                if(i - mp[prefix[i]] > right - left) {
                    left = mp[prefix[i]];
                    right = i;
                }
            }else {
                mp[prefix[i]] = i;
            }
        }
        return {array.begin() + left, array.begin() + right};
    }
};

