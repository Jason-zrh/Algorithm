#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class ExamTracker {
public:
    ExamTracker() {
        prefix.emplace_back(0);
    }
    
    void record(int time, int score) {
        index.emplace_back(time);
        prefix.emplace_back(prefix.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        // 第一个 >= startTime 的位置
        int left_pos = lowerBound(index, startTime);

        // 第一个 > endTime 的位置
        int right_pos = upperBound(index, endTime) - 1;

        // 没有合法记录
        if (left_pos > right_pos) {
            return 0;
        }

        return prefix[right_pos + 1] - prefix[left_pos];
    }

private:
    // 返回第一个 >= k 的位置
    int lowerBound(vector<long long>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    // 返回第一个 > k 的位置
    int upperBound(vector<long long>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    vector<long long> prefix;
    vector<long long> index;
};