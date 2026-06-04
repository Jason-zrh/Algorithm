#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> similarString(string& str) {
        vector<int> v(26, 0);
        for(int i = 0 ; i < str.size(); i++) {
            if(v[str[i] - 'a'] == 0) {
                v[str[i] - 'a'] = 1;
            }
        }
        return v;
    }

    int similarPairs(vector<string>& words) {
        int res = 0;
        map<vector<int>, int> mp;
        for(int i = 0; i < words.size(); i++) {
            vector<int> vc = similarString(words[i]);
            res += mp[vc];
            mp[vc]++;
        }
        return res;
    }
};

