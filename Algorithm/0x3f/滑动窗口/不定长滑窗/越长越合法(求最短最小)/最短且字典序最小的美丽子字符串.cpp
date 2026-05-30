#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "", window = "";
        int left = 0, right = 0, n = s.size(), cnt = 0;
        for(right = 0; right < n; right++){
            // 入窗口
            window += s[right];
            if(s[right] == '1')
                cnt++;
            while(cnt == k){
                if(res.size() == 0 || res.size() > window.size() || (res.size() == window.size() && window < res)){
                    res = window;
                }

                if(s[left] == '1')
                    cnt--;
                window.erase(0, 1);
                left++;
            }
        }
        return res;
    }
};