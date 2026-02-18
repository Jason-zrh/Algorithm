#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
            return false;

        unordered_map<char, int> cnt;
        for (auto &ch : magazine)
            cnt[ch]++;

        for (auto &ch : ransomNote)
        {
            cnt[ch]--;
            if (cnt[ch] < 0)
                return false;
        }

        return true;
    }
};