#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare(string version1, string version2)
    {
        // write code here
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2)
        {
            // 直接将版本号字符串进行枚举，不用转换成数组
            long long num1 = 0;
            while (i < n1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                // 用于循环
                i++;
            }
            // 用于跳过点
            i++;
            long long num2 = 0;
            while (j < n2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
        }
        return 0;
    }
};