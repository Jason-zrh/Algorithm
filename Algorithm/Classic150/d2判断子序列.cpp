#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        int m = s.length(), n = t.length();
        while (i < m && j < n)
        {
            if (s[i] == t[j])
                i++;
            j++;
        }

        return i == m;
    }
};