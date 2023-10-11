#include <bits/stdc++.h>
using namespace std;

int lcm(long long a, long long b)
{
    return abs(a * b) / __gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k, y, x;
        cin >> n >> k;
        if ((n & 1) == 0) {
            int m = n / 2;
            if (m & 1) {
                x = m - 1;
                y = 2;
            }
            else {
                x = m / 2;
                y = m;
            }
        }
        else {
            y = 1;
            x = (n-y) / 2;
        }
        cout << y << ' ' << x << ' ' << x << '\n';
    }

    return 0;
}
