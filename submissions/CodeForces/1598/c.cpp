#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<long long, long long> mp;
        long long sum = 0, ans = 0;
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            mp[x]++;
            sum += x;
        }

        if ((2 * sum) % n)
        {
            cout << "0\n";
            continue;
        }

        long long target = 2 * sum / n;

        for (auto p : mp)
        {
            long long x = target - p.first;
            auto x_it = mp.find(x);
            if (x_it != mp.end())
            {
                if (x == p.first)
                    ans += (p.second * (p.second - 1));
                else
                    ans += p.second * x_it->second;
            }
        }

        cout << ans / 2 << '\n';
    }

    return 0;
}
