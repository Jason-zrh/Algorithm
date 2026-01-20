#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int index = 0;
    while(index < nums.size() - 1)
    {
        // 则index就是最大的结尾
        if(nums[index] > nums[index + 1])
            break;
        index++;
    }

    // 将一个数组分为两段, 第一段0 - index, 第二段index + 1 - nums.size(), 对两段数组作二分
    // index = 3, index + 1 = 4, nums.size() - 1 = 6
    int left = 0, right = index;
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
        return left;

    if(index == nums.size()- 1)
        return -1;
        
    left = index + 1, right = nums.size() - 1;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if(nums[left] == target)
        return left;
    else
        return -1;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 3) << endl;
    return 0;
}