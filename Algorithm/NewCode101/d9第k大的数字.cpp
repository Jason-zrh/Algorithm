#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param n int整型 
     * @param K int整型 
     * @return int整型
     */
    int partition(vector<int>& a, int left, int right)
    {
        int randpos = left + rand() % (right - left + 1);
        int pivot = a[randpos];
        // 把第一个元素与pivot交换
        swap(a[randpos], a[left]);
        int i = left + 1;
        int j = right;
        while(true)
        {
            while(i <= j && a[i] < pivot)
                i++;
            while(i <= j && a[j] > pivot)
                j--;
            if(i >= j)
                break;
            swap(a[i++], a[j--]);
        }

        swap(a[left], a[j]);
        return j;
    }

    int findKth(vector<int>& a, int n, int K) {
        srand(time(nullptr));
        int target = n - K;
        int left = 0, right = n - 1;
        while(1)
        {
            int pos = partition(a, left, right);
            if(pos == target)
                return a[pos];
            if(pos > target)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }
};