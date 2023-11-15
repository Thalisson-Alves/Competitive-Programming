#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(v) dff(v); for (auto x:v) cerr << " [" << x << "]"; cerr << '\n'; 

#define all(x) x.begin(), x.end()

using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

ostream &operator<<(ostream &os, const pi &p)
{
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    ll n, m, t;
    cin >> n >> m >> t;
    vector<pi> v(n);
    for (auto i = 1; i < n; i++)
        cin >> v[i].first;
    for (auto i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        auto &[a,b] = v[x-1];
        b = y;
    }
    for (auto [a, b]: v)
    {
        t -= a;
        if (t <= 0)
            break;
        t += b;
    }
    cout << (t > 0 ? "Yes" : "No") << '\n';
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

