#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pii = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    long long sum = 0;
    for (auto c : s)
        sum += c - '0';
    cout << (sum % 9 == 0 ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t, i = 1;
    // cin >> t;
    // while (t--)
    // {
    //     cout << "Case " << i++ << ":\n";
        solve();
    // }

    return 0;
}
