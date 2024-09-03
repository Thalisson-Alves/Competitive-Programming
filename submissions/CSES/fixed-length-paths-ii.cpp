#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll res = 0;
  auto sum = [](const deque<int> &suf, int r) {
    if (r < 0) return 0;
    if (r+1 >= (int)suf.size()) return suf[0];
    return suf[0] - suf[r+1];
  };
  auto dfs = [&](auto &&self, int u, int p) -> deque<int> {
    deque<int> cur{1};
    for (auto v : g[u]) if (v != p) {
      auto ch = self(self, v, u);
      ch.push_front(ch.front());
      if (size(cur) < size(ch)) swap(cur, ch);
      for (int i = 0; i < (int)size(ch)-1; i++) ch[i] -= ch[i+1];
      for (int i = 0; i < (int)size(ch); i++)
        res += (ll)ch[i] * (sum(cur, b-i) - sum(cur, a-i-1));
      for (int i = (int)size(ch)-2; ~i; --i) ch[i] += ch[i+1];
      for (int i = 0; i < (int)size(ch); i++) cur[i] += ch[i];
    }
    return cur;
  };
  dfs(dfs, 0, -1);
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
