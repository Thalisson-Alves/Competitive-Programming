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
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<array<int, 3>> a(q);
  for (auto &[c, u, v] : a) {
    cin >> u >> v >> c;
    --u, --v;
  }
  sort(a.begin(), a.end());

  vector<int> far(n);
  iota(far.begin(), far.end(), 0);

  ll res = 0;
  UFDS ufds(n);
  for (auto [c, l, r] : a) {
    for (auto f = l; f <= r; f++) {
      f = far[ufds.find(f)];
      res += c;
      if (f+1 <= r) {
        auto nf = far[ufds.find(f+1)];
        ufds.join(f, nf);
        far[ufds.find(f)] = nf;
      }
    }
  }

  cout << (ufds.components == 1 ? res : -1) << '\n';
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
