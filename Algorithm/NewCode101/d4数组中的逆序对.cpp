#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int cnt = 0;
    int mod = 1000000007;

    void merge(vector<int>& nums, int left, int right, int mid)
    {
        // 临时数组，储存合并好的数组
        vector<int> temp(right - left + 1);
        // 分别从分割好的数组开始遍历
        int i = left, j = mid + 1;
        // 指向temp数组插入位置
        int k = 0;
        while(i <= mid && j <= right)
        {
            // 左侧数据小于右侧
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                // 逆序数组
                cnt += (mid - i + 1);
                cnt %= mod;
                temp[k++] = nums[j++];
            }
        }
        // i还没走到mid
        while(i <= mid)
            temp[k++] = nums[i++];
        
        // j还没走到right
        while(j <= right)
            temp[k++] = nums[j++];

        // 再将排序好的数组覆盖到原数组
        for(int t = 0; t < temp.size(); t++)
            nums[left + t] = temp[t];
    
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }

    int InversePairs(vector<int>& nums) 
    {
        mergeSort(nums, 0, nums.size() - 1);
        return cnt % mod;
    }
};
