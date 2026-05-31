#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        long long opened = 0;      // 已经使用过的桌子数
        long long seated = 0;      // 已经入座的人数
        long long emptySeats = 0;  // 非空桌子里剩余的空座位数
        long long flexA = 0;       // 可以被转换成“开桌人”的 A 的数量

        for (char c : u) {
            if (c == 'I') {
                // I 必须坐空桌
                if (opened < x) {
                    opened++;
                    seated++;
                    emptySeats += s - 1;
                }
            } 
            else if (c == 'E') {
                // E 必须坐非空桌
                if (emptySeats > 0) {
                    seated++;
                    emptySeats--;
                } 
                else if (opened < x && flexA > 0) {
                    // 把之前一个坐旧桌的 A 转换成开新桌的人
                    flexA--;
                    opened++;
                    emptySeats += s;

                    // 当前 E 入座
                    seated++;
                    emptySeats--;
                }
            } 
            else {
                // A 可以坐任意桌
                if (emptySeats > 0) {
                    // 优先坐已有非空桌，保留空桌给未来的 I
                    seated++;
                    emptySeats--;
                    flexA++;
                } 
                else if (opened < x) {
                    // 没有旧桌空位，只能开新桌
                    opened++;
                    seated++;
                    emptySeats += s - 1;
                }
            }
        }

        cout << seated << '\n';
    }

    return 0;
}