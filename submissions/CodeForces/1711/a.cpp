#include <bits/stdc++.h>
using namespace std;

const auto PI = acos(-1);

template <typename T> bool equals(T a, T b)
{
    if (is_floating_point<T>::value)
    {
        const double EPS{1e-6};

        return fabs(a - b) < EPS;
    }
    else
        return a == b;
}

template <typename T> istream &operator>>(istream &is, T &v)
{
    for (auto &x : v) is >> x;
    return is;
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
    int n;
    cin >> n;
    cout << n << " \n"[n == 1];
    for (auto i = 1; i < n; i++)
        cout << i << " \n"[i == n-1];
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
