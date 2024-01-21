#include <bits/stdc++.h>
using namespace std;

#define debug(x, s) cerr << #x << ": " << x << s
#define debugn(x) debug(x, '\n')
#define debugv(x) cerr << #x << ": "; for (const auto &a : x) cerr << a << ' '; cerr << '\n';

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (auto &x : v) for (auto &y : x) cin >> y;
    vector<vector<int>> dp(n, vector<int>(3));
    for (auto i = 0; i < 3; i++)
        dp[0][i] = v[0][i];
    for (auto i = 1; i < n; i++)
        for (auto j = 0; j < 3; j++)
            dp[i][j] = max(dp[i - 1][(j + 1)%3], dp[i-1][(j+2)%3]) + v[i][j];
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n;
    // cin >> n;
    // for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}
