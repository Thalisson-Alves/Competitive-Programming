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

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template<typename T1, typename T2>
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

bool f(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first == b.first || a.second == b.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v)
        cin >> x;

    if (n == 1 || (n == 2 && f(v[0], v[1])))
    {
        cout << "-1\n";
        return;
    }

    auto mn = *min_element(v.begin(), v.end()), mx = *max_element(v.begin(), v.end());
    if (f(mx, mn))
    {
        for (const auto &x : v)
        {
            if (x.first < mn.first || (x.first == mn.first && x.second > mn.second))
                mn = x;
            if (x.first > mx.first || (x.first == mx.first && x.second < mx.second))
                mx = x;
        }
    }

    cout << abs(mn.first - mx.first) * abs(mn.second - mx.second) << '\n';
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
