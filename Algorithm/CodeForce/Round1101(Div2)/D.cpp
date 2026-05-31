#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<int> a;
vector<tuple<int, int, int>> ans;

void solve(int m, int from, int to, int aux) {
    if (m == 0) return;

    int k = a[m];
    int r = m - 1 - k;

    if (k == 0) {
        solve(m - 1, from, aux, to);

        ans.push_back({m, from, to});

        solve(m - 1, aux, to, from);
    } else {
        solve(r, from, aux, to);

        ans.push_back({m, from, to});

        solve(r, aux, from, to);

        solve(m - 1, from, to, aux);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        a.assign(n + 1, 0);

        bool ok = true;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            if (a[i] >= i) {
                ok = false;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        ans.clear();

        solve(n, 1, 3, 2);

        cout << "YES\n";
        cout << ans.size() << '\n';

        for (auto [id, from, to] : ans) {
            cout << id << ' ' << from << ' ' << to << '\n';
        }
    }

    return 0;
}