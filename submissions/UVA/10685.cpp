#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void dfs(vector<vector<int>> &g, int s, vector<int> &dist)
{
    for (auto x : g[s])
        if (dist[x] == x)
        {
            dist[x] = dist[s];
            dfs(g, x, dist);
        }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == m and n == 0) return;
    unordered_map<string, int> mp;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s] = i;
    }
    for (auto i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        auto ai = mp[a], bi = mp[b];
        v[ai].push_back(bi);
        v[bi].push_back(ai);
    }
    vector<int> dist(n);
    iota(all(dist), 0);
    for (auto i = 0; i < n; i++)
    {
        if (dist[i] == i)
            dfs(v, i, dist);
        cerr << dfn(dist[i]);
    }
    map<int, int> his;
    auto ans = 0;
    for (auto x : dist)
        ans = max(ans, ++his[x]);
    cout << ans << '\n';
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

