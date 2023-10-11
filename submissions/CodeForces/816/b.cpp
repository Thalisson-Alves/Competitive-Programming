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

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> v(200010);
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v[x]++;
        v[y+1]--;
    }
    for (auto i = 0u; i < v.size() - 1; i++)
        v[i + 1] += v[i];
    for (auto &x : v)
        x = (x >= k);
    for (auto i = 0u; i < v.size() - 1; i++)
        v[i + 1] += v[i];

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << v[y] - v[x - 1] << '\n';
    }
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

