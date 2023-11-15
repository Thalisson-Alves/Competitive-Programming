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
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    vector<ll> ps(n+1);
    for (auto i = 0; i < n; i++)
        ps[i+1] = ps[i] + v[i];
    for (auto x = 0; x <= n; x++)
    {
        auto li = lower_bound(all(ps), ps[x] + p);
        if (li == ps.end() or *li - ps[x] != p) continue;
        auto lj = lower_bound(all(ps), *li + q);
        if (lj == ps.end() or *lj - *li != q) continue;
        auto lk = lower_bound(all(ps), *lj + r);
        if (lk == ps.end() or *lk - *lj != r) continue;
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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

