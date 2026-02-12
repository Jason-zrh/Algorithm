#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    // 从右到左找第一个数字大于左侧数字的数
    int n = nums.size();

    int pos = n - 1;
    while (pos >= 1 && nums[pos] <= nums[pos - 1])
    {
        pos--;
    }
    // 等下排序的起点
    if(pos >= 1)
    {
        int val = nums[pos - 1];
        int i = n - 1;
        while(i >= pos && nums[i] <= val)
            i--;
        swap(nums[pos - 1], nums[i]);
    }
    reverse(nums.begin() + pos, nums.end());
}


int main()
{
    vector<int> nums = {1, 3, 5, 4, 2};
    nextPermutation(nums);
    for(auto e : nums)
        cout << e << " ";
    cout << endl;
    return 0;
}