#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// class Solution
// {
// public:
//     bool IsPalindrome(string s)
//     {
//         int left = 0, right = s.size() - 1;
//         while(left < right)
//         {
//             if(s[left] != s[right])
//                 return false;
//             left++;
//             right--;
//         }
//         return true;
//     }

//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         int max_len = 0;
//         int x = 0, y = 0;
//         vector<vector<int>> dp(n, vector<int>(n));
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i; j < n; j++)
//             {
//                 // 是回文子串
//                 if(IsPalindrome(s.substr(i, j - i + 1)))
//                 {
//                     dp[i][j] = j - i + 1;
//                     if(max_len < dp[i][j])
//                     {
//                         max_len = max(max_len, dp[i][j]);
//                         x = i, y = j;
//                     }
//                 }
//                 else
//                     dp[i][j] = dp[i][j - 1];
//             }
//         }

//         return s.substr(x, y - x + 1);
//     }
// };

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int start = 0;

        // 枚举子串长度
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j])
                {
                    if (len <= 2 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;

                        if (len > maxLen)
                        {
                            maxLen = len;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};