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

void solve()
{
    int n;
    cin >> n;
    int pos = 0, neg = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        (x > 0 ? pos++ : neg++);
    }
    cout << (pos > 1 && neg > 1 ? "No" : "Yes") << '\n';
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
