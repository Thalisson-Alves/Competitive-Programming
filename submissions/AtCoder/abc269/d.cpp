#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

const vector<pii> dir{{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

void dfs(pii q, const set<pii> &s, set<pii> &vis)
{
    vis.emplace(q);
    
    for (auto [x, y] : dir)
    {
        auto p = make_pair(x + q.first, y + q.second);
        if (s.count(p) and not vis.count(p))
            dfs(p, s, vis);
    }
}

void solve()
{
    unsigned n;
    cin >> n;
    vector<pii> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    set<pii> s(all(v)), vis;
    auto ans = 0;
    for (auto i = 0u; i < v.size() and vis.size() != n; i++)
        if (not vis.count(v[i]))
        {
            ans++;
            dfs(v[i], s, vis);
        }
    cout << ans << '\n';
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

