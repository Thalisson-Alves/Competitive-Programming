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
    int w, h, k;
    cin >> w >> h >> k;
    vector<long long> xsa(k);
    for (auto &x : xsa)
        cin >> x;
    cin >> k;
    vector<long long> xsb(k);
    for (auto &x : xsb)
        cin >> x;
    
    cin >> k;
    vector<long long> ysa(k);
    for (auto &y : ysa)
        cin >> y;
    cin >> k;
    vector<long long> ysb(k);
    for (auto &y : ysb)
        cin >> y;

    auto b1 = max((xsa.back() - xsa.front()) * h, (xsb.back() - xsb.front()) * h);
    auto b2 = max((ysa.back() - ysa.front()) * w, (ysb.back() - ysb.front()) * w);
    cout << max(b1, b2) << '\n';
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
