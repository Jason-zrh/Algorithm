#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    vector<int> nums;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            nums.push_back(matrix[i][j]);
        }
    }

    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (nums[left] == target)
        return true;
    else
        return false;
}


int main()
{

    return 0;
}