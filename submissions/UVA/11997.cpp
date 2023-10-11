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
    struct T
    {
        ll val, pos;
        bool operator<(const T &o) const {return val > o.val;}
    };
    for (int n; cin >> n;)
    {
        vector<ll> ans(n);
        for (auto &x : ans) cin >> x;
        sort(all(ans));

        for (auto _ = 1; _ < n; _++)
        {
            vector<ll> b(n);
            for (auto &x : b) cin >> x;
            sort(all(b));

            priority_queue<T>pq;
            for (auto i = 0; i < n; i++)
                pq.push({ans[i] + b[0], 0});
            
            for (auto i = 0; i < n; i++)
            {
                auto cur = pq.top();
                pq.pop();
                ans[i] = cur.val;
                if (cur.pos < n - 1)
                    pq.push({cur.val - b[cur.pos] + b[cur.pos + 1], cur.pos + 1});
            }
        }
        for (auto i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}

