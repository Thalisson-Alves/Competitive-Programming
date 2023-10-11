#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a < b ? b : a)

void solve()
{
    long long n, h, k;
    scanf(" %lld %lld %lld", &n, &h, &k);
    long long ans = 0, c = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        scanf(" %lld", &x);
        if (x + c <= h)
            c += x;
        else
            ans++, c = x;

        ans += c / k;
        c %= k;
    }

    ans += c / k + (c % k != 0);
    printf("%lld\n", ans);
}

int main()
{
    // int t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
    //     cout << "Case #" << i << ": ";
        solve();
    // }

    return 0;
}
