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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    auto l = 0, r = n - 1, tl = 0, tr = 0;
    while (l <= r)
    {
        if (tl or tr)
        {
            auto mn = min(tl, tr);
            tl -= mn;
            tr -= mn;
        }

        if (tl == 0) tl = v[l++];
        if (tr == 0 and l <= r) tr = v[r--];
    }
    cout << l << ' ' << n -1 - r << '\n';
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

