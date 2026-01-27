#include <vector>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> prefix(nums.size() + 1, 1);
    vector<int> suffix(nums.size() + 1, 1);
    
    for (int i = 1; i <= nums.size(); i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];
    for (int i = nums.size() - 1; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i];

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
        ans.push_back(prefix[i] * suffix[i + 1]);

    return ans;
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    productExceptSelf(nums);
}