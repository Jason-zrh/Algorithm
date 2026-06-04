#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         int res = 0;
//         for(int i = 0; i < time.size(); i++) {
//             int n = time[i];
//             for(int j = i + 1; j < time.size(); j++) {
//                 if((n + time[j]) % 60 == 0)
//                     res++;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int res = 0;    
        for(int i = 0; i < time.size(); i++) {
            int n = time[i] % 60;
            res += mp[(60 - n) % 60];
            mp[n]++;
        }
        return res;
    }
};