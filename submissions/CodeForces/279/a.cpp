#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pii = pair<int, int>;

bool same_line(int a, int b, int c, int d, int e, int f)
{
    if (a == c && e == a && ((b <= f && f <= d) || (b >= f && f >= d)))
        return true;
    if (b == d && b == f && ((a <= e && e <= c) || (a >= e && e >= c)))
        return true;
    return false;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int dir = 0;
    int px = 0, py = 0, cx = 0, cy = 0, ans = 0, inc = 0;
    while (true)
    {
        inc += (dir % 2) == 0;
        px = cx;
        py = cy;
        if (dir == 0)
            cx += inc;
        else if (dir == 1)
            cy += inc;
        else if (dir == 2)
            cx -= inc;
        else
            cy -= inc;

        dir = (dir + 1) % 4;
        if (!same_line(px, py, cx, cy, x, y))
            ans++;
        else
            break;
    }
    cout << ans << '\n';
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
