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

template<typename T>
double D(const pair<T, T>& P, const pair<T, T>& Q, const pair<T, T>& R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) -
           (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

void dfs(vector<vector<int>> &g, vector<int> &v, int i)
{
    for (auto x : g[i])
        if (v[x] < 0)
        {
            v[x] = v[i];
            dfs(g, v, x);
        }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<vector<int>> g(n);
    for (auto i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ps(n, -1);
    for (auto i = 0; i < n; i++)
        if (ps[i] < 0)
        {
            ps[i] = i;
            dfs(g, ps, i);
        }
    vector<ll> mp(n);
    for (auto i = 0; i < n; i++)
        mp[ps[i]] += v[i];
    string ans = "POSSIBLE";
    for (auto x : mp)
        if (x) ans = "IMPOSSIBLE";
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

