#include <bits/stdc++.h>
using namespace std;

#define debug(x, s) cerr << #x << ": " << x << s
#define debugn(x) debug(x, '\n')
#define debugv(x) cerr << #x << ": "; for (const auto &a : x) cerr << a << ' '; cerr << '\n';

template<typename T = int> inline T inf() { return numeric_limits<T>::max(); }

void solve()
{
    long long x, y;
    cin >> x >> y;
    if (x >= y)
    {
        cout << x - y << '\n';
        return;
    }
    set<long long> s;
    queue<pair<long long, long long>> q;
    q.emplace(make_pair(y, 0));
    auto ans = y - x;
    while (not q.empty())
    {
        auto [a, b] = q.front();
        s.emplace(a);
        q.pop();
        if (b > ans)
            continue;
        ans = min(ans, abs(a - x) + b);
        if (a == x)
        {
            ans = min(ans, b);
            break;
        }
        if (a & 1)
        {
            if (s.find(a + 1) == s.end())
                q.emplace(make_pair(a + 1, b + 1));
            if (s.find(a - 1) == s.end())
                q.emplace(make_pair(a - 1, b + 1));
        }
        else if (s.find(a >> 1) == s.end())
            q.emplace(make_pair(a >> 1, b + 1));
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n;
    // cin >> n;
    // for (auto t = 1; t <= n; t++)
    {
        // cout << "Case #" << t << '\n';
        solve();
    }

	return 0;
}
