#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto i = 0u; i < x.size(); i++) cerr << x[i] << " \n"[i==x.size()-1];
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

auto dfs(const vector<vector<int>> &g, vector<bool> &vis, int s)
{
    vis[s] = 1;
    stack<int> st;
    st.push(s);
    auto c = 0, twos = 0;

    for (; not st.empty(); c++)
    {
        auto cur = st.top();
        st.pop();
        twos += g[cur].size() == 2;
        for (auto x : g[cur])
            if (not vis[x])
            {
                vis[x] = 1;
                st.push(x);
            }
    }
    return c == twos;
}

inline auto solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int x, y; cin >> x >> y;)
    {
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    vector<bool> vis(n);
    auto ans = 0;
    for (auto i = 0; i < n; i++)
        if (not vis[i])
            ans += dfs(g, vis, i);
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

