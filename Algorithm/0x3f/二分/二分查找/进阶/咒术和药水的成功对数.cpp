#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(int i = 0; i < spells.size(); i++) {
            int left = 0, right = potions.size() - 1;
            int mid = 0;
            while(left <= right) {
                mid = left + (right - left) / 2;
                if(spells[i] * potions[mid] < success) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
            if(left == potions.size()) {
                res.emplace_back(0);
            }else {
                res.emplace_back(potions.size() - left);
            }
        }
        return res;
    }
};

