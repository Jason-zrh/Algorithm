#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int j = 0, k = 0;
        int dirc = 0;
        for(int i = 1; i <= n * n; i++)
        {
            ans[j][k] = i;
            int p = j + dx[dirc];
            int q = k + dy[dirc];
            if(p < 0 || q < 0 || p >= n || q >= n || ans[p][q] > 0)
            {
                dirc = (dirc + 1) % 4;
            }
            j += dx[dirc];
            k += dy[dirc];
        }
        return ans;
    }
};