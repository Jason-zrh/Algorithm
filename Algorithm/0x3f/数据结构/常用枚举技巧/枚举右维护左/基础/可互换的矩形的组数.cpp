#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long res = 0;
        for(int i = 0; i < rectangles.size(); i++) {
            double proportion = (double)rectangles[i][0] / rectangles[i][1];
            if(mp.find(proportion) != mp.end()) {
                res += mp[proportion];
            }
            mp[proportion]++;
        }
        return res;
    }
};
