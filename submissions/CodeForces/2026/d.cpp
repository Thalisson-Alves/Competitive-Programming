#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), p1(n+1), p2(n+1), p3(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p1[i+1] = a[i] + p1[i];
    p2[i+1] = p2[i] + p1[i+1];
  }
  auto sum_seg = [&](int i, int j) { return p2[j+1] - p2[i] - (j-i+1) * p1[i]; };
  for (int i = 0; i < n; i++) {
    p3[i+1] = p3[i] + sum_seg(i, n-1);
  }
  vector<ll> start(n);
  for (ll i = n, s = 0; auto &x : start) x = s, s += i--;
  auto indices = [&](ll i) {
    int j = int(upper_bound(begin(start), end(start), i) - 1 - begin(start));
    return make_pair(j, int(i-start[j]+j));
  };
  auto sum = [&](int i, int j) { return sum_seg(i, j) + p3[i]; };
  auto pref = [&](ll i) {
    if (i < 0) return 0ll;
    auto [l, r] = indices(i);
    return sum(l, r);
  };
  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    --l, --r;
    cout << pref(r) - pref(l-1) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
