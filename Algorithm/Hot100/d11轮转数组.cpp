#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return;
    if (k == nums.size())
        return;
    reverse(nums.begin(), nums.end());
    auto it = nums.begin();
    it += (k % nums.size()); // 移动步数可能大于数组长度
    reverse(nums.begin(), it);
    reverse(it, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);

    for (auto e : nums)
        cout << e << " ";
    cout << endl;
    return 0;
}
