#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int x) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < x) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }


    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        // 遍历arr1，在arr2中用二分查找abs(num1 - num2) <= d的第一个值(num1 - num2 <= d || num2 - num1 <= d)
        int res = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int x = arr1[i];
            // 找第一个x - d的值
            int pos = lower_bound(arr2, x - d);
            if(pos == arr2.size() || pos > x + d) {
                res++;
            }
        }
        return res;
    }
};