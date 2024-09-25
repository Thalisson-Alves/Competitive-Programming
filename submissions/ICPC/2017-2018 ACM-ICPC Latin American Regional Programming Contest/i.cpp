#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct UFDS {
  vector<pair<int, int>> ps;
  vector<int> sz;
  UFDS(int n = 0) : ps(n, {-1, -1}), sz(n, 1) {}
  int find(int x) { return (~ps[x].first ? find(ps[x].first) : x); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y, int w) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = {x, w};
    sz[x] += sz[y];
    return true;
  }
  int query(int x, int y) const {
    int res = -1;
    while (x != y) {
      int &low = (sz[x] < sz[y] ? x : y);
      res = max(res, ps[low].second);
      low = ps[low].first;
    }
    return res;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> es(m);
  map<pair<int, int>, int> mp;
  for (auto &[w, u, v] : es) cin >> u >> v >> w, --u, --v, mp[minmax(u, v)] = w;
  UFDS ufds(n);
  sort(begin(es), end(es));
  ll base = 0;
  for (auto [w, u, v] : es) if (ufds.join(u, v, w)) {
    base += w;
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int mx = ufds.query(u, v);
    cout << base - mx + mp[minmax(u, v)] << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
