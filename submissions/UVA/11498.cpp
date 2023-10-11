#include <bits/stdc++.h>
using namespace std;

#define df(x) " [" #x "]: " << x
#define dfn(x) df(x) << '\n'

const auto PI = acos(-1);

template <typename T = int> T inf() { return numeric_limits<T>::max(); }

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

void solve(int t)
{
    pair<int, int> p;
    cin >> p;
    while (t--)
    {
        pair<int, int> x;
        cin >> x;
        if (p.first == x.first || p.second == x.second)
        {
            cout << "divisa\n";
            continue;
        }
        string ans;
        ans += "NS"[p.second > x.second];
        ans += "EO"[p.first >x.first];
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
        // {
        //     cout << "Case #" << i << ": ";
        // solve();
    // }
    int t =1;
    while (1)
    {
        cin >> t;
        if (not t)break;
        solve(t);
    }

    return 0;
}
