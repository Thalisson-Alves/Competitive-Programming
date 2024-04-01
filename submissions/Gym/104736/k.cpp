#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v)
    cin >> x, --x;

  if (k > 19) {
    vector<bool> remain(k, 1);
    vector<int> first(k, -1);
    vector<int> perm;
    for (int i = 0; i < n; i++) {
      int pos = -1;
      for (int j = i; j < n; j++) {
        if (remain[v[j]] and first[v[j]] < i) {
          first[v[j]] = pos = j;
        }
      }
      if (pos == -1)
        break;
      i = pos;
      perm.push_back(v[pos]);
      remain[v[pos]] = 0;
    }
    for (int i = 0; i < k; i++) {
      if (remain[i])
        perm.push_back(i);
    }
    for (int i = 0; i < k; i++) {
      cout << perm[i] + 1 << " \n"[i == k - 1];
    }
  } else {
    vector<vector<int>> nxt(k, vector<int>(n + 1));
    for (int i = 0; i < k; i++) {
      nxt[i][n] = n;
      for (int j = n - 1; ~j; --j) {
        nxt[i][j] = nxt[i][j + 1];
        if (v[j] == i) nxt[i][j] = j;
      }
    }

    vector<pair<int, int>> dp(1 << k);
    auto dfs = [&](auto &&self, int mask) -> int {
      auto &memo = dp[mask];
      if (memo.first)
        return memo.first;
      for (int i = 0; i < k; i++)
        if (mask & (1 << i)) {
          auto value = nxt[i][self(self, mask ^ (1 << i))];
          if (value > memo.first) {
            memo = {value, i};
          }
        }
      return memo.first;
    };

    if (dfs(dfs, (1 << k) - 1) < n) {
      cout << "*\n";
      return;
    }

    int msk = (1 << k) - 1;
    vector<int> res;
    while (msk) {
      auto [value, from] = dp[msk];
      res.push_back(from + 1);
      msk ^= 1 << from;
    }
    for (int i = 0; i < k; i++)
      cout << res[k - i - 1] << " \n"[i == k-1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
