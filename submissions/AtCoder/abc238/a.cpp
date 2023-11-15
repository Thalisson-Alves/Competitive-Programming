#include <bits/stdc++.h>
using namespace std;

const double EPS{1e-9};

string solve(int n)
{
    if (n >= 5)
        return "Yes";
    return (pow(2, n) > n * n ? "Yes" : "No");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    auto ans = solve(n);
    cout << ans << '\n';

    return 0;
}
