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
    vector<pii> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    string s;
    cin >> s;
    map<int, vector<pii>> vs;
    for (int i = 0; i < n; i++)
        vs[v[i].second].push_back(make_pair(v[i].first, s[i] == 'R'));

    for (auto &it : vs)
    {
        auto x = it.second;
        int cr = -1, fl = -1;
        for (auto i = 0u; i < x.size(); i++)
        {
            if (x[i].second && (cr == -1 || x[i].first < cr))
                cr = x[i].first;
            if (!x[i].second && x[i].first > fl)
                fl = x[i].first;
        }
        if (cr != -1 && fl != -1 && cr < fl)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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
