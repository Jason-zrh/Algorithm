#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int ans = 0;
    vector<int> prefix(nums.size() + 1, 0);
    unordered_map<int, int> mp;
    mp[0]++;
    for (int i = 1; i <= nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];

        auto it = mp.find(prefix[i] - k);
        if(it != mp.end())
            ans += it->second;

        mp[prefix[i]]++;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1};
    cout << subarraySum(nums, 0) << endl;
    return 0;
}