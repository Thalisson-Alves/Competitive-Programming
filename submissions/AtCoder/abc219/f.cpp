#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  ll k;
  cin >> s >> k;

  vector<pair<int, int>> vis;
  int a = 0, b = 0;
  vis.emplace_back(a, b);
  for (auto c : s) {
    switch (c) {
    case 'L': --a; break;
    case 'R': ++a; break;
    case 'U': --b; break;
    case 'D': ++b; break;
    }
    vis.emplace_back(a, b);
  }
  sort(vis.begin(), vis.end());
  vis.erase(unique(vis.begin(), vis.end()), vis.end());

  if (a == 0 and b == 0) {
    cout << vis.size() << '\n';
    return;
  }

  if (a == 0) {
    swap(a, b);
    for (auto &[x, y] : vis)
      swap(x, y);
  }

  if (a < 0) {
    a = -a;
    for (auto &[x, y] : vis)
      x = -x;
  }

  map<pair<ll, ll>, vector<int>> group;
  for (int i = 0; i < (int)vis.size(); i++) {
    auto [x, y] = vis[i];
    int q = (x >= 0 ? x / a : -((-x + a - 1) / a));
    auto f = x - q * a;
    auto g = y - q * b;
    group[{f, g}].push_back(q);
  }
  ll res = 0;
  for (auto &[_, v] : group) {
    sort(v.begin(), v.end());
    res += k;
    for (int i = 1; i < (int)v.size(); i++) {
      res += min(k, (ll)v[i] - v[i-1]);
    }
  }
  cout << res << '\n';
}

// clang-format off
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
