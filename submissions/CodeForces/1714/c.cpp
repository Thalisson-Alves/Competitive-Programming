#include <bits/stdc++.h>
using namespace std;

#define df(x) " [" #x "]: " << x
#define dfn(x) df(x) << '\n'

#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;
    string ans;
    for (auto d = 9; n; d--)
    {
        auto value = min(d, n);
        ans += '0' + value;
        n -= value;
    }
    reverse(all(ans));
    cout << ans << '\n';
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

