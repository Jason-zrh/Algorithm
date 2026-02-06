#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int size = 2;
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 1)
            return {{1}};
        ans.push_back({1});
        for(int i = 1; i < numRows; i++)
        {
            vector<int> level(size, 1);
            for(int j = 1; j < size - 1; j++)
                level[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            ans.push_back(level);
            size++;
        }
        return ans;
    }
};