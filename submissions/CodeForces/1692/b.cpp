#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
    map<int, int> mp;
    for (auto x : v) mp[x]++;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        auto &[k, v] = *itr;
        if (v <= 1)
            continue;

        auto p = v & 1;
        v = 1;
        if (p == 0)
        {
            auto d = 1;
            auto it = itr;
            for (it++; it != mp.end(); it++)
                if (it->second > 1) {
                    d = 0;
                    it->second--;
                    break;
                }
            v -= d;
        }
    }
    auto ans = 0;
    for (auto [_, x] : mp)
        ans += x;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int n;
    cin >> n;
    for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}
