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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (auto i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }
    for (auto &x : v)
    {
        cout << x.size();
        sort(all(x));
        for (auto y : x)
            cout << ' ' << y+1;
        cout << '\n';
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
