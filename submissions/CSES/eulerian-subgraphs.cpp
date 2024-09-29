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

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;
  UFDS ufds(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ufds.join(--u, --v);
  }
  cout << fpow(2, m-n+ufds.components, 1e9+7) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
