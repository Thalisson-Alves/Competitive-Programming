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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), c(n + m + 1), b(m + 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : c)
        cin >> x;

    reverse(a.begin(), a.end());
    reverse(c.begin(), c.end());
    
    for (int i = 0; i <= m; i++)
    {
        auto sum = 0;
        for (int j = 0; j < i; j++)
            if (i - j <= n)
                sum += a[i - j] * b[j];
        b[i] = (c[i] - sum) / a[0];
    }

    for (int i = m; i >= 0; i--)
        cout << b[i] << " \n"[!i];
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
