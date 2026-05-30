#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lower_bound(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(letters[mid] < target) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos = lower_bound(letters, target + 1);
        if(pos == letters.size()) {
            return letters[0];
        }
        return letters[pos];
    }
};