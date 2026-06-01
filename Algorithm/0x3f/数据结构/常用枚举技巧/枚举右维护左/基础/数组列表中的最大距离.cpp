#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mini = arrays[0][0], maxi = arrays[0][arrays[0].size() - 1];
        for(int i = 1; i < arrays.size(); i++) {
            res = max(res, max(abs(arrays[i][0] - maxi), abs(arrays[i][arrays[i].size() - 1] - mini)));
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        }
        return res;
    }
};
