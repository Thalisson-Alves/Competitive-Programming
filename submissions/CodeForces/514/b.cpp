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
    pair<int, int> pos;
    cin >> n >> pos.first >> pos.second;
    vector<pair<int, int>> ps(n);
    for (auto &p : ps)
        cin >> p.first >> p.second;
    map<double, int> mp;
    for (auto &p : ps)
    {
        double key = (p.first != pos.first ? (p.second - pos.second) / (double)(p.first - pos.first) : numeric_limits<double>::infinity());
        mp[key]++;
    }
    cout << mp.size() << '\n';
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
