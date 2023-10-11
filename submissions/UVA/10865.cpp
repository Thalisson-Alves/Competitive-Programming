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
    if (!n)
        return;
    vector<pair<int, int>> ps(n);
    for (auto &x : ps)
        cin >> x.first >> x.second;
    auto center = ps[ps.size() / 2];
    int stan = 0, ollie = 0;
    for (const auto &x : ps)
    {
        if (x.first == center.first || x.second == center.second)
            continue;
        if ((x.first > center.first && x.second > center.second) || (x.first < center.first && x.second < center.second))
            stan++;
        else
            ollie++;
    }
    cout << stan << ' ' << ollie << '\n';
    solve();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
