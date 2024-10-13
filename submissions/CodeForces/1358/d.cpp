#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n; ll m;
  cin >> n >> m;
  vector<int> d(n);
  for (auto &x : d) cin >> x;
  d.insert(end(d), begin(d), end(d));
  vector<ll> pdays(size(d)+1), psums(size(d)+1);
  constexpr auto sum = [](int a, int b) { return (a + b) * (b - a + 1ll) / 2; };
  for (int i = 0; i < (int)size(d); i++) {
    pdays[i+1] = pdays[i] + d[i];
    psums[i+1] = psums[i] + sum(1, d[i]);
  }
  auto f = [&](int month, int day) {
    int l = month, r = n*2;
    while (l <= r) {
      int mid = midpoint(l, r);
      if (pdays[mid+1]-pdays[month]-(day-1) >= m) r = mid - 1;
      else l = mid + 1;
    }
    int last_day = d[l] - int((pdays[l+1]-pdays[month]-day+1)-m);
    return psums[l+1]-psums[month]-sum(0, day-1)-sum(last_day+1, d[l]);
  };
  ll res = 0;
  for (int i = 0; i < n; i++) {
    int l = 1, r = d[i];
    while (l <= r) {
      auto m1 = l + (r - l) / 3;
      auto m2 = r - (r - l) / 3;
      if (f(i, m1) <= f(i, m2)) l = m1 + 1;
      else r = m2 - 1;
    }
    res = max(res, f(i, r));
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
