#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.size() == 1)
            return 1;

        int pos = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[pos] == nums[i])
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