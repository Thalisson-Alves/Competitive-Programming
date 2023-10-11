#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)                                                                                                      \
    cerr << #v << ": ";                                                                                                \
    for (auto x : v)                                                                                                   \
        cerr << x << ' ';                                                                                              \
    cerr << '\n'

const auto PI = acos(-1);

template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << ' ' << p.second;
    return os;
}

string operator*(const string &s, int x)
{
    string result = s;
    result.reserve(s.size() * x);
    while (--x)
        result += s;
    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string mn(n, '0'), mx(n, '0');
    auto sum = 0;
    for (int i = 0; i < n && sum != m; i++)
    {
        auto v = min(m - sum, 9);
        mx[i] = '0' + v;
        mn[n - i - 1] = '0' + v;
        sum += v;

        if (i + 1 < n && sum == m)
            mn[n - i - 1]--, mn[0] = '1';
    }

    if (sum != m || (mn[0] == '0' && n > 1) || (mx[0] == '0' && n > 1))
        cout << "-1 -1\n";
    else
        cout << mn << ' ' << mx << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
    //     cout << "Case #" << i << ": ";
    solve();
    // }

    return 0;
}
