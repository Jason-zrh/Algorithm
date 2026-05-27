#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int left = 0, right = 0, n = answerKey.size();
        int ans = 0;

        int Tcnt = 0, Fcnt = 0;

        for(right = 0; right < n; right++)
        {
            char c = answerKey[right];
            if(c == 'T')
                Tcnt++;
            else
                Fcnt++;

            while(min(Tcnt, Fcnt) > k)
            {
                c = answerKey[left];
                if(c == 'T')
                    Tcnt--;
                else
                    Fcnt--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};