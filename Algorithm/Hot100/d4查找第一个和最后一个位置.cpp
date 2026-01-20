#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
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
    // 要检查一下看看结果对不对
    if(nums[left] != target)
        return {-1, -1};
    ans.push_back(left);

    left = 0, right = nums.size() - 1;
    while(left < right)
    {
        mid = (left + right + 1) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid;
    }
    ans.push_back(left);
    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 6);
    for(auto& e : ans)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}