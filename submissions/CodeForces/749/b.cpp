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

pii dist(const pii &a, const pii &b)
{
    return {a.first - b.first, a.second - b.second};
}

pii add(const pii &a, const pii &b)
{
    return {a.first + b.first, a.second + b.second};
}

void solve()
{
    pii a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    set<pii> v;
    // A
    v.emplace(add(b, dist(a, c)));
    v.emplace(add(c, dist(a, b)));
    // B
    v.emplace(add(a, dist(b, c)));
    v.emplace(add(c, dist(b, a)));
    // C
    v.emplace(add(a, dist(c, b)));
    v.emplace(add(b, dist(c, a)));

    cout << v.size() << '\n';
    for (const auto &p : v)
        cout << p.first << ' ' << p.second << '\n';
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
