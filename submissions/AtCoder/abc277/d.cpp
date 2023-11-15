#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{-1,0},{0,-1},{1,0},{0,1}};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), vis(n);
    auto sum = 0ll;
    for (auto &x : v) cin >> x, sum += x;
    sort(all(v));
    auto ans = inf<ll>();
    for (auto cur = 0ll, top = v[cur]; not vis[cur]; top=v[cur])
    {
        auto total = 0ll;
        for (auto i = 0; i < n and (v[cur] == top or v[cur] == (top+1)%m); i++, total+=v[cur], top=v[cur], cur=(cur+1)%n)
            vis[cur] = 1;
        ans = min(ans, sum-total);
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
