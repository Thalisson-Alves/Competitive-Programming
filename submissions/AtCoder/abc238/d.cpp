#include <bits/stdc++.h>
using namespace std;

string solve(long long a, long long s)
{
    long long d = s - 2 * a;
    if (d >= 0 && !(d & a))
        return "Yes";
    return "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long a, s;
        cin >> a >> s;
        auto ans = solve(a, s);
        cout << ans << '\n';
    }

    return 0;
}
