#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < hours.size(); i++) {
            int h = hours[i] % 24;
            res += mp[(24 - h) % 24];
            mp[h]++;
        }
        return res;
    }
};

