#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int ans = 0;
    for (auto x : st)
    {
        // if (st.contains(x - 1)) C++20
        if(st.find(x - 1) != st.end())
            continue;

        int y = x + 1;
        // while (st.contains(y)) C++20
        while(st.find(y) != st.end())
        {
            y++;
        }
        ans = max(ans, y - x);
    }
    return ans;
}

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums) << endl;

    return 0;
}