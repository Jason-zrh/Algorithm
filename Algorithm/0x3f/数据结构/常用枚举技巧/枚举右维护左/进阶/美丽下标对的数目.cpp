#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> digitalNum(int num) {
        // <第一位，最后一位>
        int firstNum, endNum;
        endNum = num % 10;
        while(num / 10 != 0) {
            num /= 10;
        }
        firstNum = num;
        return {firstNum, endNum};
    }

    int gcd(int x, int y) {
        while(y) {
            int t = x % y;
            x = y;
            y = t; 
        }
        return x;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> digital = digitalNum(nums[i]);
            for(int j = i + 1; j < nums.size(); j++) {
                if(gcd(digital[0], digitalNum(nums[j])[1]) == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

