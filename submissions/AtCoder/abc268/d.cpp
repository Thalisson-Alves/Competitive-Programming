#include <bits/stdc++.h>
using namespace std;

#define cerr cerr << "\x1B[31m"

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void all_comb(string s, set<string> &p, vector<string> &v, int mn)
{
    if (s.size() > 16)
        return;
    if (p.size() == 0u and s.size() >= 3)
    {
        v.emplace_back(s);
        return;
    }
    for (const auto &x : p)
    {
        auto pc = p;
        pc.erase(pc.lower_bound(x));
        for (auto i = mn; i > 0; i--)
            all_comb(s + string(i, '_') + x, pc, v, mn - i);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    set<string> a, b;
    auto max_s = 0;
    for (auto i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.emplace(s);
        max_s += s.size();
    }
    for (auto i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        b.emplace(s);
    }
    vector<string> ac;
    const auto max_ = 16 - max_s;
    for (const auto &x : a)
    {
        auto pc = a;
        pc.erase(pc.lower_bound(x));
        all_comb(x, pc, ac, max_);
    }

    for (const auto &s : ac)
    {
        if (not b.count(s))
        {
            cout << s << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //for (auto i = 1; i <= t; i++)
    solve();

    return 0;
}

