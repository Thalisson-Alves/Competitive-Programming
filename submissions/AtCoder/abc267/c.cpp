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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto i = 0; i < n; i++)
        cin >> v[i];
    ll p = 0, s = 0;
    for (auto i = 0; i < m; i++)
    {
        p += (i + 1) * v[i];
        s += v[i];
    }
    auto ans = p;
    for (auto i = m; i < n; i++)
    {
        p += m * v[i] - s;
        s += v[i] - v[i - m];
        ans = max(ans, p);
    }
    cout << ans << '\n';
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

