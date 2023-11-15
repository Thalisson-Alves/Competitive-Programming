#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pi = pair<int, int>;

template <typename T>
T D(const pair<T, T> &a, const pair<T, T> &b, const pair<T, T> &c)
{
    return (a.first * b.second + a.second * c.first + b.first * c.second) -
           (c.first * b.second + c.second * a.first + b.first * a.second);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    bool ans = true;
    int x = a[0], y = b[0], nx = 0, ny = 0;
    for (int i = 1; i < n; i++, x = nx, y = ny, nx = 0, ny = 0)
    {
        if ((x && abs(a[i] - x) <= k) || (y && abs(a[i] - y) <= k))
            nx = a[i];
        if ((x && abs(b[i] - x) <= k) || (y && abs(b[i] - y) <= k))
            ny = b[i];

        if (nx == 0 && ny == 0)
        {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
        // {
        //     cout << "Case " << i++ << ":\n";
        solve();
    // }

    return 0;
}
