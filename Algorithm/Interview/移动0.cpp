#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[left]);
                left++;
            }
        }
    }
};