#include <bits/stdc++.h>
using namespace std;

const double EPS{1e-9};

string solve(vector<int> &vs)
{
    sort(vs.begin(), vs.end());
    for (size_t i = 0; i < vs.size() - 2; i++)
        if (vs[i] + vs[i + 1] > vs[i + 2] && vs[i] + vs[i + 2] > vs[i + 1] && vs[i + 1] + vs[i + 2] > vs[i])
            return "YES";
    return "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vs(n);
    for (auto & x : vs) cin >> x;

    auto ans = solve(vs);
    cout << ans << '\n';

    return 0;
}
