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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  reverse(v.begin(), v.end());
  while (v.size() and v.back() == 1) v.pop_back();
  reverse(v.begin(), v.end());
  if (find(v.begin(), v.end(), 1) != v.end()) {
    cout << "-1\n";
    return;
  }

  constexpr double eps = 1e-9;
  double prev = log(log(v[0]));
  ll res = 0;
  for (int i = 1; i < (int)v.size(); i++) {
    double cur = log(log(v[i]));
    double dif = prev - cur;
    if (dif <= eps) {
      prev = cur;
      continue;
    }
    int cnt = 1 + (dif - eps) / log(2);
    res += cnt;
    prev = cur + cnt * log(2);
  }
  cout << res << '\n';
}

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
