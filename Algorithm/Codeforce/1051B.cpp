#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

ll solve_one(vector<ll> &a, vector<int> &b) 
{
    int n = (int)a.size();
    sort(a.begin(), a.end(), greater<ll>()); // 商品价格降序
    sort(b.begin(), b.end());                // 优惠券升序

    // 选前缀：保证 sum(b) <= n
    int prefix_sum = 0, t = 0;
    for (int x : b) 
    {
        if (prefix_sum + x <= n) 
        {
            prefix_sum += x;
            t++;
        } else break;
    }
    vector<int> selected(b.begin(), b.begin() + t);

    ll total = accumulate(a.begin(), a.end(), 0LL);

    // 处理 b=1 的券：直接让最贵的商品免费
    int ones = count(selected.begin(), selected.end(), 1);
    ll free_sum = 0;
    for (int i = 0; i < ones; i++) 
    {
        free_sum += a[i];
    }

    // 剩余商品
    vector<ll> arr_rem(a.begin() + ones, a.end());

    // 处理 b>1 的券
    vector<int> others;
    for (int x : selected) if (x > 1) others.push_back(x);

    ll best_free = -1;
    // 尝试两种顺序：升序、降序
    for (int mode = 0; mode < 2; mode++) 
    {
        vector<int> order = others;
        if (mode == 0) sort(order.begin(), order.end());
        else sort(order.rbegin(), order.rend());

        ll f = free_sum;
        int p = 0;
        bool ok = true;
        for (int x : order) 
        {
            if (p + x - 1 < (int)arr_rem.size()) 
            {
                f += arr_rem[p + x - 1];
                p += x;
            } else 
            {
                ok = false; break;
            }
        }
        if (ok) best_free = max(best_free, f);
    }

    if (best_free == -1) return total; // 没有可行方案（理论上不会出现）
    return total - best_free;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(k);
        for (int i = 0; i < k; i++) cin >> b[i];
        cout << solve_one(a, b) << "\n";
    }
    return 1;
}