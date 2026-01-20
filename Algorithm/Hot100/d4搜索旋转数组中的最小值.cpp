#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    int x = nums[right];
    while(left < right)
    {
        mid = (left + right) / 2;
        if(nums[mid] > x)
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}

int main()
{


    return 0;
}