#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << x
#define dfn(x) df(x) << '\n'
#define dfv(x) dff(x); for (auto y: x) cerr << y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    map<int, set<int>> mp;
    for (auto i = 0; i < n; i++)
        mp[v[i]].insert(i);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (mp[a].begin() == mp[a].end() or mp[b].rbegin() == mp[b].rend())
            cout << "NO\n";
        else
            cout << (*mp[a].begin() < *mp[b].rbegin() ? "YES" : "NO") << '\n';
    }
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

