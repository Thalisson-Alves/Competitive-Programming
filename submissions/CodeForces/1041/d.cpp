#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

inline auto solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    vector<pair<ll, ll>> dp(n);
    dp[0].second = v[0].second - v[0].first;
    for (auto i = 1; i < n; i++)
    {
        dp[i].second = v[i].second - v[i].first;
        dp[i].first = dp[i-1].first + v[i].first - v[i-1].second;
    }
    auto ans = 0ll;
    for (auto i = 0; i < n; i++)
    {
        auto x = upper_bound(all(dp), make_pair(m + dp[i].first, 0ll)) - 1 - dp.begin();
        auto w = v[x].second - v[i].first + m - (dp[x].first - dp[i].first);
        ans = max(ans, w);
    }
    cout << ans << '\n';
}

/*
12 -> 0,  1
20 -> 4,  4
26 -> 9,  1
33 -> 13, 3
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

