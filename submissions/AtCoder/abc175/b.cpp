#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pi = pair<int, int>;

void solve()
{
    int n;;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                if (v[i] != v[j] && v[j] != v[k] && v[i] != v[k] && v[i] + v[j] > v[k] && v[j] + v[k] > v[i] && v[i] + v[k] > v[j])
                    ans++;

    cout << ans << '\n';
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
