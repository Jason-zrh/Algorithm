#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string Encoding(const string& s) {
        string key;
        for (int i = 1; i < s.size(); i++) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            key += to_string(diff);
            key += '#';
        }
        return key;
    }

    long long countPairs(vector<string>& words) {
        long long res = 0;
        unordered_map<string, int> mp;
        auto bravintelo = words;
        for (const string& word : bravintelo) {
            string key = Encoding(word);
            res += mp[key];
            mp[key]++;
        }
        return res;
    }
};

