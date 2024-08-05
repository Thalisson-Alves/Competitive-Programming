#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  map<int, int> ids;
  {
    set<int> st;
    for (int i = 0; i < n; i++) {
      st.insert((m-a[i])%m);
      st.insert(b[i]);
    }
    int id = 0;
    for (auto x : st)
      ids[x] = id++;
  }
  vector<vector<pair<int, ll>>> g(n+ids.size());
  for (auto it = begin(ids); it != end(ids); it++) {
    auto nxt = (next(it) == end(ids) ? begin(ids) : next(it));
    g[it->second+n].emplace_back(nxt->second+n, (nxt->first-it->first+m)%m);
  }
  for (int i = 0; i < n; i++) {
    g[i].emplace_back(ids[m-a[i]]+n, 0);
    g[ids[b[i]]+n].emplace_back(i, 0);
  }
  vector<ll> dist(g.size(), numeric_limits<ll>::max());
  dist[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, 0);
  while (not pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();
    if (cost != dist[u]) continue;

    for (auto [v, w] : g[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[u] + w, v);
      }
    }
  }

  cout << dist[n-1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
