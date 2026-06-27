#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i][j - 1] ^ prefix[i - 1][j] ^ prefix[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            }
        }

        vector<int> nums;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                nums.push_back(prefix[i + 1][j + 1]);
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

