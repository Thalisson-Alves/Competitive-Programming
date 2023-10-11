#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        vector<int> vs(m);
        for (int i = 0, x; i < n; i++) cin >> x, vs[x%m]++;
        for (int i = 0; i < m; i++) {
            auto &a = vs[i], &b = vs[(m-i) % m];
            if (!a) {
                ans += b;
                b = 0;
            }
            else if (!b) {
                ans += a;
                a = 0;
            }
            else if (a > b) {
                ans++;
                a -= b+1;
                b = 0;
            }
            else if (a < b) {
                ans++;
                b -= a+1;
                a = 0;
            }
            else {
                ans++;
                a = 0;
                b = 0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
