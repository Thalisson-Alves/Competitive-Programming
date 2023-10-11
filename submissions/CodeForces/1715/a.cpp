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
    int n, m;
    cin >> n >> m;
    auto ans = n + m + min(n, m);
    cout << ans - 2 - (n==1 and m==n) << '\n';
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

