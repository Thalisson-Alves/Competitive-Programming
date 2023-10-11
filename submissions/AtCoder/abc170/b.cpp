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
    int x, y;
    cin >> x >> y;
    if ((4 * x - y) % 2)
    {
        cout << "No\n";
        return;
    }
    auto b = (4 * x - y) / 2;
    auto a = x - b;
    cout << (a + b != x || a < 0 || b < 0 ? "No":  "Yes") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
    //     cout << "Case " << i++ << ":\n";
    solve();
    // }

    return 0;
}
