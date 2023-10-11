#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << '\n'

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double EPS{1e-9};

void solve()
{
    double n, r;
    cin >> n >> r;
    double s = sin((360.0 / (2 * n)) * M_PI / 180.0);
    cout << fixed << setprecision(13) << (r * s) / (1 - s) << '\n';
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
