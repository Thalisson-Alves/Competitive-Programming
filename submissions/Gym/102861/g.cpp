#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int best = 0, s = 0;
    while (n--)
    {
        int x;
        cin >> x;
        s += x;
        best = max(best, s);
    }
    cout << 100 + best << '\n';

    return 0;
}
