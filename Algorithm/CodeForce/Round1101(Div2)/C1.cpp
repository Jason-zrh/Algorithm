#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        const int NEG = -1e9;

        vector<int> dp(x + 1, NEG);
        dp[0] = 0;

        for (char c : u) {
            vector<int> ndp = dp; // 当前这个人可以不安排

            for (int j = 0; j <= x; j++) {
                if (dp[j] == NEG) continue;

                int seated = dp[j];
                int capacity = j * s;

                if (c == 'I') {
                    // 内向者只能坐空桌
                    if (j < x) {
                        ndp[j + 1] = max(ndp[j + 1], seated + 1);
                    }
                } else if (c == 'E') {
                    // 外向者只能坐非空且没满的桌
                    if (capacity - seated > 0) {
                        ndp[j] = max(ndp[j], seated + 1);
                    }
                } else {
                    // A 可以坐空桌
                    if (j < x) {
                        ndp[j + 1] = max(ndp[j + 1], seated + 1);
                    }

                    // A 也可以坐非空且没满的桌
                    if (capacity - seated > 0) {
                        ndp[j] = max(ndp[j], seated + 1);
                    }
                }
            }

            dp = ndp;
        }

        int ans = 0;
        for (int j = 0; j <= x; j++) {
            ans = max(ans, dp[j]);
        }

        cout << ans << '\n';
    }

    return 0;
}