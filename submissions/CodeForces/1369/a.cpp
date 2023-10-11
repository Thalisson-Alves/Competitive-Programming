#include <bits/stdc++.h>
using namespace std;

const double EPS{1e-9};

string solve(int n)
{
    return (n % 4 == 0 ? "Yes" : "No");
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
        auto ans = solve(n);
        cout << ans << endl;
    }

    return 0;
}
