#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lower_bound(vector<int> nums, int x) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < x) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }

    int lower_bound(string s, char x) {
        int left = 0, right = s.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(s[mid] < x) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }

    int f(string s) {
        sort(s.begin(), s.end());
        int pos = lower_bound(s, s[0] + 1) - 1;
        return pos + 1;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> fw(words.size());
        for(int i = 0; i < words.size(); i++) {
            fw[i] = f(words[i]);
        }

        sort(fw.begin(), fw.end());

        for(int i = 0; i < queries.size(); i++) {
            res.emplace_back(words.size() - lower_bound(fw, f(queries[i])));
        }
        return res;
    }
};

