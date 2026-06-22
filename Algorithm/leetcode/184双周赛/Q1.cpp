#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        while (n > 0) {
            if ((n & 1) && (n & 2)) {
                cnt++;
            }
            n >>= 1;
        }
        return cnt == 1;
    }
};