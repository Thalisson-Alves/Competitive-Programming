#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
  vector<int> ps, sz;
  int comp;
  DSU(int n = 0) : ps(n, -1), sz(n, 1), comp(n) {}
  int find(int x) { return (~ps[x] ? (ps[x] = find(ps[x])) : x); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --comp;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++comp;
    return id;
  };
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 3>> es(m);
  for (auto &[w, u, v] : es) cin >> u >> v >> w, --u, --v;
  vector<int> ca(n), cb(n);
  for (int i = 0, x; i < k; i++) cin >> x, ca[--x]++;
  for (int i = 0, x; i < k; i++) cin >> x, cb[--x]++;
  sort(begin(es), end(es));
  DSU dsu(n);
  ll res = 0;
  for (auto [w, u, v] : es) {
    int ru = dsu.find(u);
    int rv = dsu.find(v);
    if (ru == rv) continue;
    dsu.join(ru, rv);
    int r = dsu.find(u);
    ca[r] += ca[r^ru^rv];
    cb[r] += cb[r^ru^rv];
    auto mn = min(ca[r], cb[r]);
    res += (ll)w * mn;
    ca[r] -= mn;
    cb[r] -= mn;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
