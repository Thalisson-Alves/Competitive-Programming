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
    int n, c = 0, mx = 0;
    cin >> n;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        if (x == y)
            c++;
        else
            c = 0;
        mx = max(mx, c);
    }
    cout << (mx >= 3 ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
