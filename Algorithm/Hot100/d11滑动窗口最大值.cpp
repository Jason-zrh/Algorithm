#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

// 单调队列(用双端队列 + 单调性实现)
// vector<int> maxSlidingWindow(vector<int> &nums, int k)
// {
//     vector<int> ans;
//     deque<pair<int, int>> maxNum; // 左侧存的是下标，右侧存的是值
//     int left = 0;
//     for(int right = 0; right < nums.size(); right++)
//     {
//         int num = nums[right];
//         // 入窗口, 更新值
//         // 先比较再入队列，如果新的值比之前的大，直接把前面的全部删掉

//         while(!maxNum.empty() && maxNum.back().second <= num)
//             maxNum.pop_back();

//         maxNum.push_back(make_pair(right, num));

//         // 窗口没到大小继续进窗口
//         if(right - left + 1 < k)
//             continue;

//         // 窗口构成更新答案
//         ans.push_back(maxNum.front().second);

//         // 左指针右移出窗口并同时判断出窗口的值在不在队列中
//         if(maxNum.front().first == left)
//             maxNum.pop_front();
//         // 左指针移动
//         left++;
//     }
//     return ans;
// }

// 优先级队列
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i)
    {
        q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};
    for (int i = k; i < n; ++i)
    {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k)
        {
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = maxSlidingWindow(nums, 3);
    for (auto &e : ans)
        cout << e << " ";
    cout << endl;
    return 0;
}