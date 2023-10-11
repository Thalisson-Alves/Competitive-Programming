#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
    int m, n;
    cin >> m >> n;
    if (not (m or n)) return;
    vector<ii> ms(m);
    for (auto i = 0; i < m; i++) cin >> ms[i].first, ms[i].second = i;
    vector<int> ns(n);
    for (auto &x : ns) cin >> x;

    sort(all(ms), greater<ii>());

    vector<vector<int>> ans(m);
    for (auto x : ms)
        for (int i = 0; i < n; i++)
        {
            if ((int)ans[x.second].size() == x.first) break;
            if (ns[i])
                ans[x.second].push_back(i+1), ns[i]--;
        }

    bool has_ans = true;
    for (auto x : ms)
        if ((int)ans[x.second].size() < x.first)
            has_ans = false;

    cout << has_ans << '\n';
    if (has_ans)
    {
        for (auto v : ans)
            for (unsigned i = 0; i < v.size(); i++)
                cout << v[i] << " \n"[i + 1 == v.size()];
    }

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

