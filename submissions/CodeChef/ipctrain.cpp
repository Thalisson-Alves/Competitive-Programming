#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    using T = tuple<ll, ll, ll>;
    vector<T> v(n);

    for (auto &[x, y, z] : v) cin >> x >> y >> z;
    sort(all(v));

    priority_queue<pair<ll, ll>> pq;
    for (auto i = 0, cur_day = 1; cur_day <= m; cur_day++)
    {
        for (; i < n and get<0>(v[i]) == cur_day; i++)
            pq.emplace(get<2>(v[i]), get<1>(v[i]));

        if (pq.empty()) continue;

        auto [s, t] = pq.top();
        pq.pop();
        if (t > 1)
            pq.emplace(s, t-1);
    }
    auto ans = 0ll;
    while (not pq.empty())
    {
        auto [s, t] = pq.top();
        pq.pop();
        ans += s * t;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}
