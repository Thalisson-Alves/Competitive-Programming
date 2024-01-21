#include <bits/stdc++.h>
using namespace std;

#define debug(x, s) cerr << #x << ": " << x << s
#define debugn(x) debug(x, '\n')
#define debugv(x) cerr << #x << ": "; for (const auto &a : x) cerr << a << ' '; cerr << '\n';

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<int> dp(n, 1e9 + 3);
    dp[0] = 0;
    for (auto i = 0; i < n; i++)
        for (auto j = i + 1; j < n && j <= i + k; j++)
            if (j < n)
                dp[j] = min(dp[j], dp[i] + abs(v[i] - v[j]));
    cout << dp[n - 1] << '\n';
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
