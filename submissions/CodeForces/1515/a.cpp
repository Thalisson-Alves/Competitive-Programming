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
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (auto &a : w)
        cin >> a;

    auto sum = 0;
    auto ans = true;
    for (auto i = 0; i < n; i++)
    {
        sum += w[i];
        if (sum == x)
        {
            if (i == n - 1)
                ans = false;
            else
                swap(w[i], w[i + 1]);
            break;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
    if (ans)
        for (auto i = 0; i < n; i++)
            cout << w[i] << " \n"[i == n-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    // {
    //     cout << "Case " << i++ << ":\n";
    solve();
    // }

    return 0;
}
