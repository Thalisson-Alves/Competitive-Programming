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
    auto q = sqrt(x * x + y * y);
    cout << setprecision(12) << x / q << ' ' << y / q << '\n';
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
