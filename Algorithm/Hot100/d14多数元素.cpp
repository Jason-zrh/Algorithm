#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> cnt;
    for (auto &e : nums)
        cnt[e]++;

    int n = nums.size();
    auto it = cnt.begin();
    int ans = 0;
    while (it != cnt.end())
    {
        if (it->second > (n / 2))
        {
            ans = it->first;
            break;
        }
        it++;
    }
    return ans;
}