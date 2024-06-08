#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct UFDS {
  vector<int> ps, sz;
  int components;

  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }

  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }

  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };

  void reset() {
    for (int i = 0; i < (int)ps.size(); i++) {
      ps[i] = i;
      sz[i] = 1;
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<unsigned, int, int>> es(m);
  for (auto &[w, u, v] : es) cin >> u >> v >> w, --u, --v;
  sort(es.begin(), es.end());

  auto is_connected = [&](unsigned mask) {
    UFDS base(n);
    auto ufds = base;
    for (auto [w, u, v] : es) if ((w & mask) == w) {
      ufds.join(u, v);
    }
    return ufds.components == 1;
  };

  unsigned res = -1u;
  for (int i = 31; ~i; --i) {
    if (is_connected(res ^ (1u << i)))
      res ^= (1u << i);
  }
  cout << res << '\n';
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
