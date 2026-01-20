#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size();
    int mid = 0;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 7) << endl; 
    return 0;
}