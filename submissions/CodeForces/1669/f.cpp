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
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    auto ans = make_pair(-1, n);
    int i = 0, j = n - 1;
    auto si = 0LL, sj = 0LL;
    while (i <= j)
    {
        if (si == sj)
        {
            if (v[i] >= v[j])
                si += v[i++];
            else
                sj += v[j--];
        }

        while (i <= j && si > sj)
            sj += v[j--];
        while (i <= j && si < sj)
            si += v[i++];

        if (si == sj)
            ans = make_pair(i - 1, j + 1);
    }
    cout << ans.first + 1 + n - ans.second << '\n';
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
