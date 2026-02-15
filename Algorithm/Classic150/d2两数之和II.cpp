#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        vector<int> ans;
        while (i <= j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                ans.emplace_back(i + 1);
                ans.emplace_back(j + 1);
                break;
            }
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return ans;
    }
};