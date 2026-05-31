// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int t = 0;
//     cin >> t;

//     while(t--) {
//         int n = 0;
//         cin >> n;
//         vector<int> nums(n);
//         for(int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }
//         sort(nums.begin(), nums.end());


//         if(n % 2 != 0) {
//             int left = (n / 2) - 1;
//             int right = (n / 2) + 1;
//             while(nums[left] == nums[right] && nums[left] == nums[n / 2]) {
//                 left--;
//                 right++;
//             }
//             cout << left + 1 << endl;
//         }else {
//             int left = (n / 2) - 1;
//             int right = n / 2;
//             while(nums[left] == nums[right]) {
//                 left--;
//                 right++;
//             }
//             cout << left + 1 << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        int ans = n;

        for (int i = 0; i < n; ) {
            int j = i;

            while (j < n && nums[j] == nums[i]) {
                j++;
            }

            // nums[i] ~ nums[j - 1] 都等于当前枚举的位置
            int left = i;       // 小于 nums[i] 的人数
            int right = n - j;   // 大于 nums[i] 的人数

            ans = min(ans, max(left, right));

            i = j;
        }

        cout << ans << endl;
    }

    return 0;
}