#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> mp(n);
  for (int i = 0, x; i < n; i++) cin >> x, mp[x]++;
  constexpr ll mod = 1e9+7;
  ll res = 0;
  for (auto [_, x] : mp)
    (res += x * (res + 1ll) % mod) %= mod;
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
