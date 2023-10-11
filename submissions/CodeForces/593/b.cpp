#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

using ll = long long;

const double EPS{1e-9};
const auto PI = acos(-1);

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
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
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<pair<long long, long long>> v(n);
    for (auto &p : v)
    {
        cin >> p;
        p = make_pair(p.first * x1 + p.second, p.first * x2 + p.second);
    }
    sort(v.begin(), v.end());
    for (auto p : v)
    {
        auto it = upper_bound(v.begin(), v.end(), make_pair(p.first, numeric_limits<long long>::max()));
        if (it == v.end()) continue;
        if (p.second > it->second)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
