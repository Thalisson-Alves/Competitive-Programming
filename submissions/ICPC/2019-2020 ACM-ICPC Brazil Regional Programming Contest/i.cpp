#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--) {
            int x; cin >> x;
            --x;
            g[i].push_back(x);
        }
    }

    constexpr ll mod = 1e9 + 7;
    vector<ll> dp(n);
    using T = bitset<2000>;
    vector<T> dp2(n);
    for (int i = m; i < n; i++) dp[i] = 1, dp2[i][i] = 1;
    auto dfs = [&](auto &&self, int u) -> void {
        auto &res = dp[u];
        if (res) return;
        for (auto v : g[u]) {
            self(self, v);
            (res += dp[v]) %= mod;
            dp2[u] |= dp2[v];
        }
    };
    for (int i = 0; i < n; i++) {
        dfs(dfs, i);
    }
    cout << dp[0] << ' ' << dp2[0].count() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
