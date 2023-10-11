#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

const static double PI = acos(-1.0);
using pi = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> h{2, 4, 5, 7, 9};
    cout << (n % 10 == 3 ? "b" : (binary_search(h.begin(), h.end(), n % 10) ? "h" : "p")) << "on\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
    //     cout << "Case " << i++ << ":\n";
    solve();
    // }

    return 0;
}
