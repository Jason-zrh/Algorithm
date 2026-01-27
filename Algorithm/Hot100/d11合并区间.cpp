#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // lambda表达式
    sort(intervals.begin(), intervals.end(),
        [](vector<int> a1, vector<int> a2)
        {
            if (a1[0] != a2[0])
                return a1[0] < a2[0];
            else
                return a1[1] < a2[1];
        });


    vector<vector<int>> ans;
    for (auto &p : intervals)
    {
        // ans存在区间且可以合并
        if (!ans.empty() && p[0] <= ans.back()[1])
            ans.back()[1] = max(p[1], ans.back()[1]);
        else
            ans.emplace_back(p);
    }
    return ans;
}

int main()
{

    return 0;
}