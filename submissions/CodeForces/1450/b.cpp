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
    int n, k;
    cin >> n >> k;
    vector<pii> v(n);
    for (auto &x : v)
        cin >> x.first >> x.second;
    for (int i = 0; i < n; i++)
    {
        bool all = true;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) > k)
            {
                all = false;
                break;
            }
        }
        if (all)
        {
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
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
