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
    int n;
    cin >> n;
    vector<long long> v(2);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x % 2]++;
    }
    int m;
    cin >> m;
    long long ans = 0;
    while (m--)
    {
        int b;
        cin >> b;
        ans += v[b % 2];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    solve();

    return 0;
}
