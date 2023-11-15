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

unsigned long long f(unsigned long long a, unsigned long long b)
{
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

void solve()
{
    unsigned long long n;
    cin >> n;

    auto ans = numeric_limits<unsigned long long>::max();
    for (auto i = 0; i < 1000000; i++)
    {
        auto l = i, r = 1000000;
        while (l <= r)
        {
            auto m = (l + r) / 2;
            auto t = f(i, m);
            if (t >= n)
            {
                ans = min(ans, t);
                r = m-1;
            }
            else
                l = m + 1;
        }
    }
    cout << (ans == numeric_limits<unsigned long long>::max() ? -1 : ans) << '\n';
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
