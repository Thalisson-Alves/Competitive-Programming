#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}
vector<int> permute_permutation(const vector<int> &p, ll k) {
  vector<bool> vis(p.size());
  vector<int> res(p.size());
  for (int i = 0; i < (int)p.size(); i++) if (!vis[i]) {
    vector<int> c;
    for (int u = i; !vis[u]; vis[u] = 1, c.push_back(u), u = p[u]);
    int shift = (int)fpow(2, k, c.size());
    for (int j = 0; j < (int)c.size(); j++)
      res[c[j]] = c[(j+shift)%c.size()];
  }
  return res;
}

void solve() {
  int n; ll k;
  cin >> n >> k;
  vector<int> p(n);
  for (auto &x : p) cin >> x, --x;
  for (int i = 0; auto x : permute_permutation(p, k))
    cout << x+1 << " \n"[++i==n];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
