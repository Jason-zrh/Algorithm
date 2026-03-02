#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> nums;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                nums.push_back(matrix[i][j]);
        }

        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        if(nums[left] == target)
            return true;
        else   
            return false;
    }
};