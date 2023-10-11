#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v) cerr << #v << ": ";for (auto x : v) cerr << x << ' ';cerr << '\n'

const double EPS{1e-9};

auto solve(vector<long long> &ys, vector<long long> &xs)
{
    sort(ys.begin(), ys.end());
    sort(xs.begin(), xs.end());

    long double ans = 0;
    for (size_t i = 0; i < ys.size(); i++)
        ans += hypot(ys[i], xs[i]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> ys, xs;
        for (int i = 0; i < 2 * n; i++)
        {
            long long x, y;
            cin >> x >> y;
            if (y) ys.emplace_back(llabs(y));
            else xs.emplace_back(llabs(x));
        }

        auto ans = solve(ys, xs);
        cout << fixed << setprecision(15) << ans << '\n';
    }

    return 0;
}
