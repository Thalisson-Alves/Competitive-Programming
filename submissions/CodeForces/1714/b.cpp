#include <bits/stdc++.h>
using namespace std;

#define df(x) " [" #x "]: " << x
#define dfn(x) df(x) << '\n'

#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    set<int> st;
    auto ans = 0;
    for (auto i = n - 1; i >= 0; i--)
    {
        if (st.count(v[i]))
            break;
        ans++;
        st.emplace(v[i]);
    }
    cout << n - ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //     cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

