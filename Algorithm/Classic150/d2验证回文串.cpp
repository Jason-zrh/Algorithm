#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for(auto& c : s)
        {
            if(isalpha(c))
            {
                if(isupper(c))
                    str += (c - 32);
                else
                    str += c;
            }
            else if(isalnum(c))
                str += c;
        }

        int start = 0, end = str.size() - 1;
        while(start < end)
        {
            if(str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};