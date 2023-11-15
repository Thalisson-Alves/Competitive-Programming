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
    auto best_odd = -1, mx_even = -1, mx_odd = -1, best_even = -1;
    for (auto i = 0; i<n; i++)
        if ((v[i]&1) and (mx_odd == -1 or (mx_odd != -1 and v[i] > v[mx_odd])))
            mx_odd = i;
        else if (not (v[i]&1) and (mx_even == -1 or (mx_even != -1 and v[i] > v[mx_even])))
            mx_even = i;

    for (auto i = 0; i < n; i++)
        if (mx_odd != -1 and (v[i]&1) and i != mx_odd)
            best_odd = max(best_odd, v[mx_odd] + v[i]);
        else if (mx_even != -1 and not(v[i]&1) and i != mx_even)
            best_even = max(best_even, v[mx_even] + v[i]);
    cout << max(best_odd, best_even) << '\n';
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

