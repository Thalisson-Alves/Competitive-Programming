#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(all(v));

    vector<int> ans;
    for (auto i = 0; i < n; i++)
    {
        auto it = lower_bound(all(ans), v[i], greater<int>());
        if (it == ans.end())
            ans.push_back(2);
        else
            (*it)++;
    }
    cout << ans.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}
