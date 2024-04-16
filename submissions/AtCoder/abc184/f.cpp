#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, mx;
  cin >> n >> mx;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  auto all = [&](auto s, auto t) -> set<int> {
    set<int> res({0});
    for (; s != t; s++) {
      for (auto it = res.rbegin(); it != res.rend(); it++) {
        if (*s + *it <= mx)
          res.insert(*s + *it);
      }
    }
    return res;
  };

  auto l = all(a.begin(), a.begin() + (n >> 1));
  auto r = all(a.begin() + (n >> 1), a.end());
  if (l.size() > r.size()) swap(l, r);

  int res = 0;
  if (l.size()) res = max(res, *l.rbegin());
  if (r.size()) res = max(res, *r.rbegin());
  for (auto x : l) {
    auto up = r.upper_bound(mx - x);
    if (up == r.begin()) continue;
    res = max(res, *prev(up) + x);
  }
  cout << res << '\n';
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
