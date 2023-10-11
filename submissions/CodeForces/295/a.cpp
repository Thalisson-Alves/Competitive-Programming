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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n), d(n+1);
    for (auto &x : v) cin >> x;
    vector<tuple<ll, ll, ll>> ops(m);
    vector<ll> dop(m+1);
    for (auto &[a, b, c] : ops) cin >> a >> b >> c;
    for (int x, y; cin >> x >> y;)
        dop[x-1]++, dop[y]--;
    auto ao = 0ll;
    for (auto i = 0; i < m; i++)
    {
        auto [a, b, c] = ops[i];
        ao += dop[i];
        d[a-1] += c * ao;
        d[b] -= c * ao;
    }
    auto av = 0ll;
    for (auto i = 0; i < n; i++)
    {
        av += d[i];
        v[i] += av;
        cout << v[i] << " \n"[i == n-1];
    }
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

