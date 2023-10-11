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
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);

    auto sa = 0LL, sb = 0LL;
    for (int i = 0; i < n-1; i++)
        sa += abs(a[i+1]-a[i]), sb += abs(b[i+1]-b[i]);

    cout << sa + sb << '\n';
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
