// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int t = 0;
//     while(t--) {
//         int n = 0;
//         vector<int> nums(n);
//         for(int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }

//         vector<int> res(n);
//         // 第一个肯定是它本身
//         res[0] = nums[0];
//         int prefix = nums[0];

//         for(int i = 1; i < n; i++) {
//             // 如果nums[i] > res[i - 1]
//             if(nums[i] >= res[i - 1]) {
//                 res[i] = res[i - 1];
//                 prefix += res[i];
//             }else {
//                 res[i] = (prefix + nums[i]) / (i + 1);
//                 prefix += res[i];
//             }
//         }

//         for(int i = 0; i < n; i++) {
//             cout << res[i] << " ";
//         }
//         cout << endl;
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

        vector<long long> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long prefix = 0;
        long long ans = 1e18;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            long long cur = prefix / (i + 1);

            ans = min(ans, cur);

            cout << ans << " ";
        }

        cout << endl;
    }

    return 0;
}