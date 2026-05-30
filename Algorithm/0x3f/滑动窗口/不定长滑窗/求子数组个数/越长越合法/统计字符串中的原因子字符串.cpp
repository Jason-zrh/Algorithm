#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    string VOWELS = "aeiou";
    int countVowelSubstrings(string word) {
        unordered_map<char, int> cnt;
        int ans = 0, start = 0, left = 0;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (VOWELS.find(ch) == string::npos) {
                cnt.clear(); // 重置
                start = left = i + 1;
                continue;
            }

            cnt[ch]++;
            while (cnt.size() == 5) { // 窗口包含所有元音
                char out = word[left];
                cnt[out]--;
                if (cnt[out] == 0) {
                    cnt.erase(out);
                }
                left++;
            }
            ans += left - start;
        }

        return ans;
    }
};