#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> g(1010, vector<ll>(1010));
    for (auto i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] += x * y;
    }
    vector<vector<ll>> ps(1020, vector<ll>(1020));
    for (auto i = 0u; i < g.size(); i++)
        for (auto j = 0u; j < g[i].size(); j++)
            ps[i][j + 1] = ps[i][j] + g[i][j];
    while (q--)
    {
        int a,b,c,d;
        cin >> a >> b>> c>>d;
        auto ans = 0ll;
        for (auto i = a + 1; i < c; i++)
            ans += ps[i][d] - ps[i][b+1];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}

