#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const double EPS{1e-9};

string solve(map<int, vector<int>> &mp)
{
    float center;
    bool is_center_set = false;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        auto &v = it->second;
        sort(v.begin(), v.end());

        if (!is_center_set)
        {
            if (v.size() % 2)
                center = v[v.size() / 2];
            else
                center = (v.front() + v.back()) / 2.0f;
            is_center_set = true;
        }

        for (size_t i = 0; i < v.size(); i++)
        {
            if ((v[i] + v[v.size() - 1 - i]) /  2.0f != center)
                return "NO";
        }
    }

    return "YES";
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
        map<int, vector<int>> mp;
        for (int i = 0, x, y; i < n; i++)
        {
            cin >> x >> y;
            mp[y].emplace_back(x);
        }

        auto ans = solve(mp);
        cout << ans << '\n';
    }

    return 0;
}
