#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, ll>> v(n);
    for (auto &[a, b] : v) cin >> a >> b;
    vector<vector<ll>> dp(n+1, vector<ll>(w+1));
    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= w; j++)
        {
            if (v[i-1].first > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], v[i-1].second + dp[i-1][j - v[i-1].first]);
        }
    }

    cout << dp[n][w] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //int n;
    //cin >> n;
    //for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}

