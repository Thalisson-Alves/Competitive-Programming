#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pi = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pi> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                v.push_back(make_pair(i, j));
        }
    sort(v.begin(), v.end());
    pi rc, lc = v[0];
    for (int i = 1; i < 3; i++)
        if (v[i].first != lc.first && v[i].second != lc.second)
            rc = v[i];
    if (rc.first == 0)
    {
        lc = v[1];
        for (int i = 1; i < 3; i++)
            if (v[i].first != lc.first && v[i].second != lc.second)
                rc = v[i];
    }
    vector<pi> ans{make_pair(lc.first, rc.second), make_pair(rc.first, lc.second)};
    for (auto x : ans)
    {
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end() || *it != x)
            cout << x.first << ' ' << x.second << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t, i = 1;
    // cin >> t;
    // while (t--)
    // {
    //     cout << "Case " << i++ << ":\n";
    solve();
    // }

    return 0;
}
