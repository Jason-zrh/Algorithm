#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> cnt(10);
        while((n / 10) > 0) {
            int num = n % 10;
            cnt[num]++;
            n /= 10;
        }
        cnt[n]++;

        int res = 0;
        for(int i = 1; i < 10; i++) {
            res += i * cnt[i];
        }
        return res;
    }
};
