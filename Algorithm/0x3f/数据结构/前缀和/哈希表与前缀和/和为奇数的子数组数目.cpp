#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isEven(int num) {
        return num % 2 == 0;
    }

    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, MOD = 1e9 + 7;
        long long ans = 0;
        int prefix = 0;
        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            if(isEven(prefix)) {
                ans = (ans + odd) % MOD;
                even++;
            }else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans % MOD;
    }
};
