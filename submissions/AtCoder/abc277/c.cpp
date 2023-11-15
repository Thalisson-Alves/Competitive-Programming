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

auto bfs(map<int, vector<int>>& mp, int s)
{
    set<int> vis;
    vis.insert(s);

    queue<int> q;
    q.push(s);

    auto ans = 0;
    while (not q.empty())
    {
        auto cur = q.front();
        q.pop();

        ans = max(ans, cur);

        for (auto x : mp[cur])
        {
            if (not vis.count(x))
            {
                vis.insert(x);
                q.push(x);
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (auto i = 0; i < n; i++)
    {
        int x, y;
        cin >> x>> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    cout << bfs(mp, 1) << '\n';
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
