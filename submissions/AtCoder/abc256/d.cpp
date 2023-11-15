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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v) cin >> x >> y;
    //sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b)
    //{
    //    return (a.second == b.second ? a.first < b.first : a.second < b.second);
    //});
    sort(all(v));
    vector<pair<int, int>> ans{v[0]};
    for (auto i = 1; i < n; i++)
    {
        if (v[i].first <= ans.back().second)
            ans.back() = make_pair(min(ans.back().first, v[i].first), max(ans.back().second, v[i].second));
        else
            ans.push_back(v[i]);
    }
    for (auto [a, b] : ans)
        cout << a << ' ' << b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t;
    //cin >> t;
    //while (t--)
    //{
        solve();
    //}

    return 0;
}

