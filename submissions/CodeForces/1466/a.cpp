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
    int n;
    cin >> n;
    vector<int> xs(n);
    for (auto &x : xs) cin >> x;
    set<double> as;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            as.emplace((xs[j] - xs[i]) / 2.0);

    cout << as.size() << '\n';
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
