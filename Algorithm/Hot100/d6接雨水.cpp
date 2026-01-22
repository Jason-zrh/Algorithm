#include <iostream>
#include <vector>

using namespace std;

// 前缀后缀和加一次遍历做法
int trap(vector<int> &height)
{
    int ans = 0;

    vector<int> prefix(height.size() + 1, 0); // 前缀和最大数组
    vector<int> suffix(height.size() + 1, 0); // 后缀和最大数组

    for(int i = 1; i <= height.size(); i++)
    {
        prefix[i] = max(prefix[i - 1], height[i - 1]);
    }
    for(int i = height.size() - 1; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], height[i]);
    }

  

    for(int i = 1; i < prefix.size(); i++)
    {
        int a = min(prefix[i], suffix[i - 1]) - height[i - 1]; 
        ans += a;
    }

    return ans;
}


// 双指针？ 待做
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height) << endl;
    return 0;
}