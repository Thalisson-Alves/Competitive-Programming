#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &vs)
{
    vector<bool> ps(360);
    ps[0] = 1;
    int i = 0;
    for (auto x : vs)
    {
        i = (i + x) % 360;
        ps[i] = true;
    }
    int ans = 0;
    int sum = 0;
    for (auto x : ps)
    {
        sum += x ? -sum : 1;
        ans = max(ans, sum);
    }
    return ans + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vs(n);
    for (auto &x : vs) cin >> x;

    auto ans = solve(vs);
    cout << ans << '\n';

    return 0;
}
