#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> cnt;
    // 出现次数最大
    int max_int = 0;
    for(auto& e : nums)
    {
        cnt[e]++;
        max_int = max(max_int, cnt[e]);
    }

    // 数组的下标是出现次数
    vector<vector<int> > buckets(max_int + 1);
    auto it = cnt.begin();    
    while(it != cnt.end())
    {
        buckets[it->second].push_back(it->first);
        it++;
    }

    // 倒序遍历
    vector<int> ans;
    int n = buckets.size() - 1;
    while (ans.size() != k)
    {
        for(auto& e : buckets[n])
            ans.push_back(e);
        n--;
    }
    return ans;
}
 

int main()
{
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    vector<int> ans = topKFrequent(nums, 2);
    for(auto& e : ans)
        cout << e << " ";
    cout << endl;
    return 0;
}