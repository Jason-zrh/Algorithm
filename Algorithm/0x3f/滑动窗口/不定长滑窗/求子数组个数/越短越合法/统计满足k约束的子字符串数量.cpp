#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt0 = 0, cnt1 = 0, res = 0;
        int left = 0, right = 0, n = s.size();
        for(right = 0; right < n; right++){
            // 入窗口
            if(s[right] == '0') {
                cnt0++;
            }else {
                cnt1++;
            }
            // 窗口非法
            while(cnt0 > k && cnt1 > k) {
                if(s[left] == '0') {
                    cnt0--;
                }else {
                    cnt1--;
                }
                left++;
            }
            // 更新结果
            res += (right - left + 1);
        }   
        return res;
    }
};