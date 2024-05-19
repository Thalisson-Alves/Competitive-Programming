#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  constexpr auto lis = [](const auto &v) {
    vector<int> res(v.size());
    vector<int> dp(v.size(), INT_MAX);
    for (int i = 0; i < (int)v.size(); i++) {
      auto it = lower_bound(dp.begin(), dp.end(), v[i]);
      *it = v[i];
      res[i] = (int)(it - dp.begin() + 1);
    }
    return res;
  };

  auto l = lis(a);
  auto mx = *max_element(l.begin(), l.end());
  reverse(a.begin(), a.end());
  for (auto &x : a) x = -x;
  auto r = lis(a);
  reverse(r.begin(), r.end());
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (r[i] + l[i] - 1 == mx)
      res.push_back(i);
  }
  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
