#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> divisors(ll n) {
  vector<ll> d;
  for (ll i = 1; i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  int res = 0;
  for (int i = 0, cnt = 1; i < n - 1; i++) {
    if (a[i] == a[i+1]) {
      if (++cnt >= n/2) {
        res = -1;
        break;
      }
      continue;
    }
    vector<int> difs;
    for (int j = i+1; j < n; j++) {
      difs.push_back(a[j]-a[i]);
    }
    map<int, int> mp;
    for (auto d : difs) {
      for (auto di : divisors(d)) ++mp[di];
    }
    for (auto [x, y] : mp) {
      if (y+cnt >= n/2) res = max(res, x);
    }
    cnt = 1;
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
