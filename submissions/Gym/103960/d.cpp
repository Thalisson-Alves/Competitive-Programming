#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  const auto mx = 1 << n;
  queue<int> q({mx >> 1});
  vector<int> dist(mx + 1, INT_MAX);
  dist[q.front()] = 0;
  while (min(dist[x], dist[y]) == INT_MAX and !q.empty()) {
    auto u = q.front();
    q.pop();
    if (dist[u] + 1 < dist[u >> 1])
      q.push(u >> 1), dist[u >> 1] = dist[u] + 1;
    if (dist[u] + 1 < dist[(u + mx) >> 1])
      q.push((u + mx) >> 1), dist[(u + mx) >> 1] = dist[u] + 1;
  }
  cout << min(dist[x], dist[y]) << '\n';
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
