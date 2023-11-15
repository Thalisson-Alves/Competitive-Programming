#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ps;
    for (int i = a; i <= b; i++)
        for (int j = c; j <= d; j++)
            if (is_prime(i + j))
                ps.emplace_back(i + j);

    string ans = "Aoki";
    for (int i = a; i <= b; i++)
    {
        auto it = upper_bound(ps.begin(), ps.end(), i+c - 1);
        if (it == ps.end() || *it > i + d)
           ans = "Takahashi";
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
