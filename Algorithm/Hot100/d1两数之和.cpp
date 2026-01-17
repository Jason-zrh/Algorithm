#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
    
// 暴力枚举
// vector<int> twoSum(vector<int>& nums, int target) 
// {
//     vector<int> ret;
//     for(int i = 0; i < nums.size() - 1; i++)
//     {
//         for(int j = i + 1; j < nums.size(); j++)
//         {
//             if(nums[i] + nums[j] == target)
//             {
//                 ret.push_back(i);
//                 ret.push_back(j);
//             }
//         }
//     }
//     return ret;
// }


// 哈希表
vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> numMap;
    vector<int> ret;
    for(int i = 0; i < nums.size(); i++)
    {
        auto it = numMap.find(target - nums[i]);
        if(it == numMap.end())
        {
            // 没找到
            numMap[nums[i]] = i; //存下标
        }
        else
        {
            // 找到了
            ret.push_back(it->second);
            ret.push_back(i);
            break;
        }      
    }
    return ret;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);


    vector<int> ret = twoSum(nums, 9);

    for(auto& e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}