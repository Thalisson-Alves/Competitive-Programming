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
    vector<vector<long long>> v(n, vector<long long>(m));
    for (auto &r : v) for (auto &x : r) cin >> x;
    auto ans = 0LL;
    for (int i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            auto sum = v[i][j];
            for (auto k = i + 1; k < n && j + (k - i) < m; k++)
                sum += v[k][j + (k - i)];
            for (auto k = i - 1; k >= 0 && j - (i - k) >= 0; k--)
                sum += v[k][j - (i - k)];
            for (auto k = j + 1; k < m && i - (k - j) >= 0; k++)
                sum += v[i - (k - j)][k];
            for (auto k = j - 1; k >= 0 && i + (j - k) < n; k--)
                sum += v[i + (j - k)][k];
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
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
