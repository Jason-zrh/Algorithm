#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;
        int res = 0;
        for(int i = 0; i < dominoes.size(); i++) {
            vector<int> v = dominoes[i];
            sort(v.begin(), v.end());
            if(mp.find(v) != mp.end()) {
                res += mp[v];
            }
            mp[v]++;
        }
        return res;
    }
};