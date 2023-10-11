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
    int n;
    cin >> n;
    auto ans = 0ll, mn = inf<ll>();
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        mn = min(mn, y);
        ans += x * mn;
    }
    cout << ans << '\n';
}

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

