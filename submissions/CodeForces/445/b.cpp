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

struct AUF
{
    vector<int> ps, sz;

    AUF(int n) : ps(n+1), sz(n+1, 1)
    {
        iota(all(ps), 0);
    }

    int find(int x)
    {
        return (x == ps[x] ? x : (ps[x] = find(ps[x])));
    }

    void u(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (sz[x] > sz[y])
            swap(x, y);
        
        ps[x] = y;
        sz[y] += sz[x];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    AUF s(n);
    for (int x, y; cin >> x >> y;)
        s.u(x, y);
    ll ans = n;
    for (int i = 1; i <= n; i++)
        ans -= i == s.find(i);
    cout << (1ll << ans) << '\n';
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

