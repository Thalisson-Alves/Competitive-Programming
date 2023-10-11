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

void solve()
{
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    sort(all(v), greater<pii>());
    int l, p;
    cin >> l >> p;
    priority_queue<int> pq;
    auto ans = 0;
    for (auto i = 0; i < n and p < l;)
    {
        for (; i < n and v[i].first >= l - p; i++)
            pq.push(v[i].second);
        if (pq.empty())
        {
            ans = -1;
            break;
        }
        ans++;
        p += pq.top();
        pq.pop();
    }
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

