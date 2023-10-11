#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)                                                                                                      \
    cerr << #v << ": ";                                                                                                \
    for (auto x : v)                                                                                                   \
        cerr << x << ' ';                                                                                              \
    cerr << '\n'

const auto PI = acos(-1);

template <typename T> bool equals(T a, T b)
{
    if (std::is_floating_point<T>::value)
    {
        const double EPS{1e-6};

        return fabs(a - b) < EPS;
    }
    else
        return a == b;
}

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
    string s;
    cin >> s;

    auto all = set<char>(s.begin(), s.end());
    if (all.size() == 1)
    {
        cout << "YES\n";
        return;
    }

    int mp[30], mx = 0;
    for (const auto &c : all)
    {
        for (auto &x : mp)
            x = 0;

        for (auto i = 0u; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                mx = 0;
                for (auto &x : mp)
                    x = 0;
                continue;
            }

            mx = max(mx, ++mp[s[i] - 'a']);

            if (mx > 1)
            {
                cout << "NO\n";
                return;
            }
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
