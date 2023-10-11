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
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    auto ans = 0;
    for (auto l = 0, r = l; l < n; l++)
    {
        for (r = l; r < n and v[l] == v[r]; r++);
        r--;
        if ((l == 0 or v[l-1] > v[l]) and (r == n-1 or v[r+1] > v[r]))
            ans++;
        l = r;
    }
    cout << (ans == 1 ? "YES" : "NO") << '\n';
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

