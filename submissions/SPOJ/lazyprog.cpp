#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    struct T
    {
        int a, b, c;
        bool operator<(const T& o)
        {
            return c<o.c;
        }
    };
    vector<T> v(n);
    for (auto &x : v) cin >> x.a >> x.b >> x.c;
    sort(all(v));

    priority_queue<pair<int, int>> pq;
    auto day = 0;
    auto money = 0.0;

    for (auto &x : v)
    {
        day += x.b;
        pq.emplace(x.a, x.b);
        while (day > x.c)
        {
            auto top = pq.top();
            pq.pop();
            if (day - top.second > x.c)
            {
                day -= top.second;
                money += (double) top.second / top.first;
            }
            else
            {
                top.second -= day - x.c;
                money += (double)(day - x.c) / top.first;
                day = x.c;
                pq.emplace(top);
            }
        }
    }
    cout << fixed << setprecision(2) << money << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; i++)
        solve();

    return 0;
}
