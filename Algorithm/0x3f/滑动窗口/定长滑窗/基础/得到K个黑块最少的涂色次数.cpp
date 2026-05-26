#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int left = 0, right = 0, window = 0, ans = 1e10;
        for(right = 0; right < n; right++){
            char c = blocks[right];
            if(c == 'W')
                window++;
            if(right - left + 1 < k)
                continue;
            ans = min(ans, window);
            c = blocks[left];
            if(c == 'W')
                window--;
            left++;
        }
        return ans;
    }
};