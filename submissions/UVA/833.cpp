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

int D(const pii &a, const pii &b, const pii &c)
{
    return (a.first * b.second + a.second * c.first + b.first * c.second) -
           (c.first * b.second + c.second * a.first + b.first * a.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<pii, pii>> ls(n);
    for (auto &x : ls)
    {
        cin >> x.first.first >> x.first.second >> x.second.first >> x.second.second;
        if (x.first.first < x.second.first)
            swap(x.first, x.second);
    }
    sort(ls.begin(), ls.end(), [](const pair<pii, pii> &a, const pair<pii, pii> &b)
         { return max(a.first.second, a.second.second) > max(b.first.second, b.second.second); });

    int m;
    cin >> m;
    while (m--)
    {
        pii p;
        cin >> p.first >> p.second;
        while (1)
        {
            // auto it = upper_bound(ls.begin(), ls.end(), p, [](const pii &a, const pair<pii, pii> &b)
            //                       { return a.first <= b.first.first && a.first >= b.second.first && D(b.first, b.second, a) < 0; });
            auto it = find_if(ls.begin(), ls.end(), [&p](const pair<pii, pii> &b)
                              { return p.first <= b.first.first && p.first >= b.second.first && D(b.first, b.second, p) < 0; });

            if (it == ls.end())
                break;

            p = it->first.second < it->second.second ? it->first : it->second;
        }
        cout << p.first << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (t)
        cout << '\n';
    }

    return 0;
}
