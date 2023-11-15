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
    int x, y, n;
    cin >> x >> y >> n;
    auto ya = (y<=3*x?n / 3:0);
    cout << ya * y + x*(n-ya*3) << '\n';
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

