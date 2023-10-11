#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

using pii = pair<int, int>;

const double EPS{1e-9};

void solve()
{
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (size_t i = 0; i < s.size() - t.size() + 1; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < t.size(); j++)
            sum += s[i+j] == t[j];
        ans = max(ans, sum);
    }
    cout << t.size() - ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
