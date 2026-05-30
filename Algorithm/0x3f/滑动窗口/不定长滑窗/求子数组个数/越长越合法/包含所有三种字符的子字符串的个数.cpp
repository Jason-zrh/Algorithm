#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0, cnta = 0, cntb = 0, cntc = 0;
        int left = 0, right = 0, n = s.size();
        for(right = 0; right < n; right++){
            switch (s[right]) {
            case 'a':
                cnta++;
                break;
            case 'b':
                cntb++;
                break;
            case 'c':
                cntc++;
                break;
            }

            while(cnta >= 1 && cntb >= 1 && cntc >= 1) {
                res += (n - right);
                switch (s[left]) {
                    case 'a':
                        cnta--;
                        break;
                    case 'b':
                        cntb--;
                        break;
                    case 'c':
                        cntc--;
                        break;
                }
                left++;
            }
        }
        return res;
    }
};