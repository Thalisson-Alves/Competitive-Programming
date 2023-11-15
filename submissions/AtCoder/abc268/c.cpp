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
    int n;
    cin >> n;
    vector<int> v(n), mp(n + 3);
    for (auto i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[(((v[i] - i) % n) + n) % n]++;
    }
    auto ans = 0;
    for (auto i = 0; i < n; i++)
        ans = max(ans, mp[i] + mp[(i+1) % n] + mp[(i+2) % n]);
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

