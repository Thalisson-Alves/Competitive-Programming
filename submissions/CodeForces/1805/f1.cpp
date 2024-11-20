#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  auto f = [&](ll x) {
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      int far = int(upper_bound(begin(a)+i, end(a), x-a[i])-begin(a)-i-1);
      if (far <= 0) break;
      cnt += far;
    }
    return cnt;
  };
  constexpr ll mod = 1e9+7;
  ll acc = 0;
  while (a.size() > 1) {
    ll k = a[0];
    for (auto &x : a) x -= k;
    (acc += acc + 2 * k % mod) %= mod;
    ll l = a[0]+a[1], r = rbegin(a)[0]+rbegin(a)[1];
    while (l <= r) {
      ll mid = midpoint(l, r);
      if (f(mid) >= (int)a.size()-1) r = mid-1;
      else l = mid+1;
    }
    vector<ll> b;
    b.reserve(a.size()-1);
    for (int i = 0; i < (int)a.size(); i++) {
      for (int j = i+1; j < (int)a.size() and a[i]+a[j] < l; j++) {
        b.push_back(a[i]+a[j]);
      }
    }
    while (b.size() < a.size()-1) b.push_back(l);
    sort(begin(b), end(b));
    swap(a, b);
  }
  cout << (a[0] + acc) % mod << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
