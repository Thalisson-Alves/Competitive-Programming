#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

int D(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c)
{
    return (a.first * b.second + a.second * c.first + b.first * c.second) - (c.first * b.second + c.second * a.first + b.first * a.second);
}

void solve()
{
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (D({0, d}, {n - d, n}, {x, y}) <= 0 &&
            D({d, 0}, {n, n - d}, {x, y}) >= 0 &&
            D({0, d}, {d, 0}, {x, y}) >= 0 &&
            D({n - d, n}, {n, n - d}, {x, y}) <= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
