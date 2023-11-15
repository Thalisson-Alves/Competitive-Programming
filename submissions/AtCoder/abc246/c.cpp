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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &a : v)
        cin >> a;

    sort(v.begin(), v.end(), greater<int>());

    for (auto &a : v) {
        if (!k)
            break;
        auto d = min(a / x, k);
        a -= d * x;
        k -= d;
    }

    sort(v.begin(), v.end(), greater<int>());

    auto ans = 0LL;
    for (auto a : v)
        ans += (k-- > 0 ? 0 : a);

    cout << ans << '\n';
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
