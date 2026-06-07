#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        _nums.resize(nums.size() + 1);
        _nums[0] = 0;
        for(int i = 1 ; i <= nums.size(); i++){
            _nums[i] = _nums[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int left, int right) {
        return _nums[right + 1] - _nums[left];
    }
private:
    vector<int> _nums;
};