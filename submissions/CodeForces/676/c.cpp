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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<int> pa(n+1), pb(n+1);
    for (auto i = 0; i < n; i++)
    {
        pa[i+1] = pa[i] + (s[i] == 'a');
        pb[i+1] = pb[i] + (s[i] == 'b');
    }

    auto ans = 0;
    for (auto i = 0; i < n; i++)
    {
        int a = upper_bound(all(pa), pa[i] + m) - 1 - pa.begin();
        int b = upper_bound(all(pb), pb[i] + m) - 1 - pb.begin();
        auto r = max(a, b);
        ans = max(ans, r - i);
    }
    cout << ans << endl;
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

