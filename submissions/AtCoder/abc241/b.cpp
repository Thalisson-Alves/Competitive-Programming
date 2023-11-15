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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    while (n--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    while (m--)
    {
        int x;
        cin >> x;
        if (!(mp[x]--))
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
