#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int left = 0, right = 0, n = s.size();
        int res = 0, same = 0;

        for(right = 0; right < n; right++)
        {
            char c = s[right];
            if((right - 1) >= 0 && c == s[right - 1])
                same++;

            while(same > 1)
            {
                if(s[left] == s[left + 1])
                    same--;
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};