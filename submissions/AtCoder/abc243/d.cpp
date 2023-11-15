#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pii = pair<int, int>;

void solve()
{
    unsigned long long n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    string m;
    for (auto c : s)
        if (c != 'U' || (!m.size() || m.back() == 'U'))
            m += c;
        else if (m.size() && m.back() != 'U')
            m.pop_back();

    cerr << m << '\n';
    auto ans = x;
    for (auto c : m)
        if (c == 'U')
            ans /= 2;
        else if (c == 'R')
            ans = ans * 2 + 1;
        else
            ans *= 2;
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
