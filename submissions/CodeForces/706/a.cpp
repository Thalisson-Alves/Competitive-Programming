#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

void solve()
{
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    double ans = numeric_limits<double>::max();
    while (n--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        ans = min(ans, hypot(a - x, b - y) / v);
    }
    cout << fixed << setprecision(15) << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
