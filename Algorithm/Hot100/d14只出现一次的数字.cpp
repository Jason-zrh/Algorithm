#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ret = 0;
    for (auto e : nums)
        ret ^= e;
    return ret;
}