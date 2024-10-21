#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) v[i] = {a[i], b[i]};
  sort(begin(v), end(v));
  ll sum = 0, res = LLONG_MAX;
  priority_queue<ll> pq;
  for (auto [m, s] : v) {
    pq.push(s);
    sum += s;
    if ((int)size(pq) > k) sum -= pq.top(), pq.pop();
    if ((int)size(pq) == k) res = min(res, m*sum);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
