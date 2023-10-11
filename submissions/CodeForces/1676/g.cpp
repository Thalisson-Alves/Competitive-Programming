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

pair<int, int> balance(const vector<vector<int>> &m, const string &s, int i)
{
    pair<int, int> ans;
    for (auto x : m[i])
    {
        auto cur = balance(m, s, x);
        ans.second += cur.second;
        ans.first += cur.first;
    }
    ans.second += (s[i] == 'W' ? 1 : -1);
    ans.first += !ans.second;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n);
    for (int i = 1, x; i < n; i++)
        cin >> x, m[x - 1].push_back(i);
    string s;
    cin >> s;
    auto [ans, _] = balance(m, s, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // {
        //     cout << "Case #" << i << ": ";
        solve();
    // }

    return 0;
}
