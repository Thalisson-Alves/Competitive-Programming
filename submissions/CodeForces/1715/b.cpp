#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(v) dff(v); for (auto x:v) cerr << " " << x; cerr << '\n'; 

#define all(x) x.begin(), x.end()

using ll = long long;
using ld = long double;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    auto m = (k * (b+1)-1);
    auto mxs = m + (k-1) * (n-1);
    auto mns = k*b;
    if (s < mns or s > mxs)
    {
        cout << "-1\n";
        return;
    }
    vector<ll> ans(n, k-1);
    ans.back() = m;
    for (auto &x : ans)
    {
        if (mxs == s)
            break;
        auto dif = (mxs - (k-1) >= s ? k-1 : mxs-s);
        x -= dif;
        mxs -= dif;
    }
    for (auto i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
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

