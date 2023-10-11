#include <bits/stdc++.h>
using namespace std;

#define df(x) " [" #x "]: " << x
#define dfn(x) df(x) << '\n'

#define all(v) v.begin(), v.end()

void solve()
{
    int n, h, m;
    cin >> n >> h >> m;
    vector<pair<int, int>> v(n);
    for (auto & x : v) cin >> x.first >> x.second;
    sort(all(v));
    auto it = lower_bound(all(v), make_pair(h, m));
    auto value = 0;
    if (it == v.end())
        value = (v[0].first * 60 + v[0].second) - (h * 60 + m - 24 * 60);
    else
        value = (it->first * 60 + it->second) - (h * 60 + m);
    cout << value / 60 << ' ' << value % 60 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //     cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

