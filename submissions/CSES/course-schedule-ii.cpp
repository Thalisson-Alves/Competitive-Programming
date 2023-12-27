#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> out(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[v].push_back(u);
    ++out[u];
  }

  priority_queue<int> pq;
  for (int i = 0; i < n; i++)
    if (!out[i])
      pq.push(i);

  vector<int> res;
  res.reserve(n);
  while (not pq.empty()) {
    auto u = pq.top();
    pq.pop();
    res.push_back(u);

    for (auto v : g[u]) {
      if (!--out[v])
        pq.push(v);
    }
  }

  for (int i = n-1; ~i; --i)
    cout << res[i]+1 << " \n"[!i];
}

int32_t main()
{
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
