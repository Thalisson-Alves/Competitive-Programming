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
    int x, y, r;
    cin >> x >> y >> r;

    double xp, yp;
    if (x)
    {
        xp = r * x / hypot(x, y);
        yp = xp * y / (double)x;
    }
    else
    {
        xp = 0.0;
        yp = r;
    }
    double mn = hypot(xp - x, yp - y);
    double mx = hypot(-xp - x, -yp - y);

    cout << fixed << setprecision(2) << min(mx, mn) << ' ' << max(mn, mx) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
