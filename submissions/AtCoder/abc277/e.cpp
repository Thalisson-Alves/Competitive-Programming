#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{-1,0},{0,-1},{1,0},{0,1}};

auto bfs(vector<vector<pair<int, int>>> &g, int s, int t, set<int> &ks)
{
    set<pair<int, int>> vis;
    vis.emplace(s, 1);
    queue<tuple<int, int, int>> q;
    q.emplace(s, 1, 0);
    while (not q.empty())
    {
        auto [cur, sw, d] = q.front();
        q.pop();

        if (ks.count(cur) and not vis.count(make_pair(cur, !sw)))
        {
            vis.emplace(cur, !sw);
            q.emplace(cur, !sw, d);
        }

        for (auto [x, y] : g[cur])
        {
            if (x == t and y == sw) return d + 1;
            if (y != sw or vis.count(make_pair(x, sw))) continue;
            vis.emplace(x, sw);
            q.emplace(x, sw, d+1);
        }
    }
    return -1;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n+1);
    for (auto i = 0; i < m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
        g[u].emplace_back(v, a);
        g[v].emplace_back(u, a);
    }
    set<int> ks;
    for (auto x = 0; cin >> x; ks.insert(x));

    cout << bfs(g, 1, n, ks) << '\n';
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
