#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // k = i - j + n -> j = i - k + n
        for(int k = 1; k < m + n; k++) {
            int min_j = max(n - k, 0); // i = 0
            int max_j = min(m - k - 1 + n, n - 1);  // i = m - 1;

            // 枚举j求i: i = k + j - n;
            vector<int> v;
            for(int j = min_j; j <= max_j; j++) {
                v.push_back(mat[k + j - n][j]);
            }

            sort(v.begin(), v.end());
            for(int j = min_j; j <= max_j; j++) {
                mat[k + j - n][j] = v[j - min_j];
            }
        }
        return mat;
    }
};
