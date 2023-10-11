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
    string c;
    cin >> m >> n >> c;
    const vector<string> order{"Ja", "Sam", "Sha", "Sid", "Tan"};
#define sti(ss) static_cast<int>(find(all(order), ss) - order.begin())
    vector<queue<int>> lists(5);
    for (auto &q : lists)
    {
        int k;
        cin >> k;
        for (string s; k; k--)
            cin >> s, q.push(sti(s));
    }
    vector<int> ans(5);
    for (auto cur = sti(c), time = 0; time < n; time += 2)
    {
        ans[cur] += min(m, n - time);
        time += m;
        auto ncur = lists[cur].front();
        lists[cur].pop();
        lists[cur].push(ncur);
        cur = ncur;
    }
    for (auto i = 0; i < 5; i++)
        cout << order[i] << ' ' << ans[i] <<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (auto i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}
