#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */

    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= right)
            temp[k++] = nums[j++];

        for (int t = 0; t < temp.size(); t++)
            nums[left + t] = temp[t];
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    int minNumberInRotateArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums[0];
    }
};