#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto &x : v)     \
        cerr << x << ' '; \
    cerr << '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long> hs(n);
    for (auto &x : hs)
        cin >> x;

    sort(hs.begin(), hs.end());

    vector<long> pp((n + 1) / 2 + 1);
    for (size_t i = 1; i < pp.size(); i++)
        pp[i] = pp[i - 1] + hs[(i - 1) * 2];

    vector<long> sp((n + 1) / 2 + 1);
    for (int i = sp.size() - 2; i >= 0; i--)
        sp[i] = sp[i + 1] + hs[2 * i];

    vector<long> pi(n / 2 + 1);
    for (size_t i = 1; i < pi.size(); i++)
        pi[i] = pi[i - 1] + hs[2 * i - 1];

    vector<long> si(n / 2 + 1);
    for (int i = si.size() - 2; i >= 0; i--)
        si[i] = si[i + 1] + hs[2 * i + 1];

    vector<long> ws(m);
    for (auto &x : ws)
        cin >> x;

    sort(ws.begin(), ws.end());

    long ans = numeric_limits<long>::max();
    for (int i = 0, j = 0; j < m; j++)
    {
        while (i < n && ws[j] > hs[i])
            i++;

        long dp, di;
        if (i % 2)
        {
            dp = pp[(i + 1) / 2] + si[i / 2];
            di = pi[i / 2] + ws[j] + sp[(i + 1) / 2];
        }
        else
        {
            dp = pp[(i + 1) / 2] + ws[j] + si[i / 2];
            di = pi[i / 2] + sp[(i + 1) / 2];
        }
        ans = min(ans, abs(dp - di));
    }
    cout << ans << '\n';

    return 0;
}
