#include <iostream>
#include <vector>

using namespace std;

// 暴力枚举，超时
int maxArea(vector<int> &height)
{
    int ans = 0;
    for (int i = 0; i < height.size() - 1; i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            ans = max(ans, ((j - i) * min(height[i], height[j])));
        }
    }
    return ans;
}

// 双指针优化
int maxArea(vector<int> &height)
{
    int ans = 0;
    int left = 0, right = height.size() - 1;
    while (left < right)
    {
        ans = max(ans, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return ans;
}

int main()
{

    return 0;
}