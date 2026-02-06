#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:

    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        stack<int> _min;
        for(auto e : prices)
        {
            if(_min.empty() || e < _min.top())
                _min.push(e);
            
            ans = max(ans, e - _min.top());
        }

        return ans;
    }
};