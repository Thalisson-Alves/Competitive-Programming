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
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--;
    c--;
    string p = 'X' + string(k-1, '.');
    auto nans = n / p.size();
    auto ans = p;
    while (--nans) ans += p;
    auto shift = 0;
    while (ans[(r + c + shift) % n] != 'X') shift++;
    //cerr << dfn(shift);

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
            cout << ans[(i + j + shift) % n];
        cout << '\n';
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

