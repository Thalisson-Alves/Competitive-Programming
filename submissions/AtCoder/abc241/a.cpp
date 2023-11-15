#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

using pii = pair<int, int>;

const double EPS{1e-9};

void solve()
{
    vector<int> v(10);
    for (auto &x : v) cin >> x;
    int p = 0;
    for (int i = 0; i < 3; i++)
        p = v[p];
    cout << p << '\n';
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
