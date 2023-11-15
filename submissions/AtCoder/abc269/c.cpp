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
    ll n;
    cin >> n;
    const auto o = 1ull;
    vector<ll> v;
    for (ll i = 0; i < 60; i++)
        if (n & (o << i)) v.push_back(i);
    for (auto i = 0ull; i < (o << v.size()); i++)
    {
        auto ans = 0ll;
        for (auto j = 0u; j < v.size(); j++)
            if (i & (o << j)) ans |= (o << v[j]);
        cout << ans << '\n';
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

