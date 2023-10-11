#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(3));
    for (auto &x : v)
        cin >> x[0] >> x[1] >> x[2];
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        string ans = "No\n";
        for (auto c : v)
        {
            if (hypot(x - c[0], y - c[1]) <= c[2])
                ans = "Yes\n";
        }
        cout << ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << i++ << ":\n";
        solve();
    }

    return 0;
}
