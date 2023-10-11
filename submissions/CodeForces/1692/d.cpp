#include <bits/stdc++.h>
using namespace std;

#define debug(x, s) cerr << x << s
#define debugn(x) cerr << x << '\n'
#define debugv(x) for (const auto &a : x) debug(a, ' '); debugn(' ')

string fmt_hour(int h, int m)
{
    stringstream ss;
    ss << setfill('0') << setw(2) << h << ":" << setw(2) << m;
    return ss.str();
}

void solve()
{
    int h, m, x;
    cin >> h;cin.ignore();
    cin >> m >> x;

    set<string> st;
    while (st.insert(fmt_hour(h, m)).second)
    {
        h = (h + (m + x) / 60) % 24;
        m = (m + x) % 60;
    }

    auto ans = 0;
    for (auto &s : st)
    {
        if (s == string(s.rbegin(), s.rend()))
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int n;
    cin >> n;
    for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}
