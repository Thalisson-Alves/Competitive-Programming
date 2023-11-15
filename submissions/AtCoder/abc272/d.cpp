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
    ll n, m;
    cin >> n>>m;
    vector<pair<int, int>> poff;
    ll r = (ll)ceil(sqrt(m));
    for (auto i = -r; i <= r; i++)
        for (auto j = -r; j <= r; j++)
            if (i*i+j*j==m)
                poff.emplace_back(i, j);

    vector<vector<int>> ans(n, vector<int>(n, -1));
    ans[0][0] = 0;

    queue<pair<int, int>> q;
    q.emplace(1, 1);
    while (not q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (const auto &[dx, dy] : poff)
        {
            auto nx = x + dx, ny = y + dy;
            if (nx > 0 and nx <= n and ny > 0 and ny <= n and ans[nx-1][ny-1] == -1)
            {
                ans[nx-1][ny-1] = ans[x-1][y-1] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            cout << ans[i][j] << " \n"[j == n-1];
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

