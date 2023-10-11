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
    auto result = s;
    result.reserve(s.size() * x);
    while (--x)
        result += s;
    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    mp[(int)2e9]++;
    auto mn = -1, mx = -1, best = -1, cur = 0;
    for (auto [k, v] : mp)
    {
        if (v >= m)
        {
            if (best < 0)
                best = k;
            else if (cur + 1 != k)
            {
                if (mx == -1 || cur - best > mx - mn)
                {
                    mn = best;
                    mx = cur;
                }
                best = k;
            }
        }
        else
        {
            if (best > 0 && (mx == -1 || cur - best > mx - mn))
            {
                mn = best;
                mx = cur;
            }

            best = -1;
            cur = -1;
        }
        cur = k;
    }
    if (mx > 0)
        cout << mn << ' ' << mx << '\n';
    else
        cout << "-1\n";
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
