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
    vector<long long> vs(n);
    for (auto &x : vs)
        cin >> x;

    auto ans = numeric_limits<long long>::max();
    for (auto pi = -1; pi < n + 1; pi++)
    {
        auto best = 0LL, prev = 0LL;
        for (auto i = pi + 1; i < n; i++)
        {
            auto d = prev / vs[i] + 1;
            best += d;
            prev = vs[i] * d;
        }
        prev = 0;
        for (auto i = pi - 1; i >= 0; i--)
        {
            auto d = prev / vs[i] + 1;
            best += d;
            prev = vs[i] * d;
        }
        ans = min(ans, best);
    }
    cout << ans << '\n';
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
