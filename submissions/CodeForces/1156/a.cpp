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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    auto ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((v[i] == 2 && v[i + 1] == 3) || (v[i] == v[i + 1]) || (v[i] == 3 && v[i + 1] == 2))
        {
            cout << "Infinite\n";
            return;
        }

        if (v[i] == 2)
            ans += 3;
        else if (v[i] == 1)
            ans += 3 + (v[i + 1] == 3);
        else
            ans += 4;
    }
    for (int i = 0; i < n - 2; i++)
        if (v[i] == 3 && v[i + 1] == 1 && v[i + 2] == 2)
            ans--;
    cout << "Finite\n" << ans << '\n';
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
