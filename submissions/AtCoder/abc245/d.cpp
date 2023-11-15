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
    auto x = 0, y = 0;
    for (auto i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        x ^= a;
        y ^= b;
    }
    cout << x << ' ' << y << '\n';
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
