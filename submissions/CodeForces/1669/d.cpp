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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a(1, s[0]);
    for (auto i = 1; i < n; i++)
    {
        if (a.back() != s[i])
            a += s[i];
    }
    auto inRange = [&a](int i) { return i >= 0 && i < (int)a.size(); };
    for (auto i = 0u; i < a.size(); i++)
    {
        auto ok = a[i] == 'W';
        if (a[i] == 'B' && ((inRange(i - 1) && a[i - 1] == 'R') || (inRange(i + 1) && a[i + 1] == 'R')))
            ok = 1;
        else if (a[i] == 'R' && ((inRange(i - 1) && a[i - 1] == 'B') || (inRange(i + 1) && a[i + 1] == 'B')))
            ok = 1;
        if (!ok)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // {
        //     cout << "Case #" << i << ": ";
        solve();
    // }

    return 0;
}
