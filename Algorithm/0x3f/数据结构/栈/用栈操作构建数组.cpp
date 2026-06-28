#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int index = 0;
        for(int i = 1; i <= n; i++) {
            if(index == target.size()) {
                break;
            }
            ans.push_back("Push");
            if(target[index] == i) {
                index++;
                continue;
            }else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};