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
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    for (auto x = a - 2; x <= a + 2; x++)
        for (auto y = b - 2; y <= b + 2; y++)
        {
            if ((a - x) * (a - x) + (b - y) * (b - y) == 5 &&
                (c - x) * (c - x) + (d - y) * (d - y) == 5)
            {
                cout << "Yes\n";
                return;
            }
        }
    cout << "No\n";
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
