#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> mp;

        for(right = 0; right < n; right++)
        {
            char c = s[right];
            mp[c]++;
            while(mp[c] > 2)
            {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, (right - left + 1));
        }
        return ans;
    }
};

