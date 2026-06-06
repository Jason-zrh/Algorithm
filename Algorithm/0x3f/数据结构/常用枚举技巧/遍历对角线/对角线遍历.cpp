#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        // k = i + j -> j = k - i
        int dict = 0;
        for(int k = 0; k < m + n - 1; k++) {
            int min_j = max(k - m + 1, 0);
            int max_j = min(k, n - 1);
            if(dict % 2 == 0) {
                // 左到右, i = k - j
                for(int j = min_j; j <= max_j; j++){
                    ans.push_back(mat[k - j][j]);
                }
            }else {
                // 右到左
                for(int j = max_j; j >= min_j; j--) {
                    ans.push_back(mat[k - j][j]);
                }
            }
            dict++;
        }
        return ans;
    }
};