#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || n == 2)
            return n;

        int pos = 1;
        for (int i = 2; i < n; i++)
        {
            if (nums[pos] == nums[pos - 1] && nums[pos] == nums[i])
                continue;
            else
            {
                pos++;
                nums[pos] = nums[i];
            }
        }
        return pos + 1;
    }
};