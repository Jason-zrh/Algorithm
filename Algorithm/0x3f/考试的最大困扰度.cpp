#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int n = answerKey.size(), left = 0;
        
        int Tcnt = 0, Fcnt = 0;
        for(int right = 0; right < n; right++)
        {
            if(answerKey[right] == 'F')
                Fcnt++;
            if(answerKey[right] == 'T')
                Tcnt++;
            while(min(Fcnt, Tcnt) > k)
            {
                if(answerKey[left] == 'T')
                    Tcnt--;
                if(answerKey[left] == 'F')
                    Fcnt--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};