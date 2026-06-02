#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = 1e9;
        unordered_map<int, int> mp;
        for(int i = 0; i < cards.size(); i++) {
            if(mp[cards[i]] != 0) {
                res = min(res, i - mp[cards[i]] + 2);
            }
            mp[cards[i]] = i + 1;
        }
        return res == 1e9 ? -1 : res;
    }
};

