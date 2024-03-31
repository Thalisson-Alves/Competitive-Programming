#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n;
  cin >> n;

  constexpr auto is_pal = [](ll x, ll b) {
    if (b < 2 or b > x) return false;

    vector<ll> s;
    while (x) {
      auto [d, r] = div(x, b);
      s.push_back(r);
      x = d;
    }
    for (int i = 0; i < (int)s.size() / 2; i++) {
      if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
  };

  set<ll> res;
  for (ll i = 1; i*i <= n; i++) if (n % i == 0) {
    if (is_pal(n, i - 1)) res.insert(i - 1);
    if (is_pal(n, n / i - 1)) res.insert(n / i - 1);
  }

  for (int i = 2; i <= min(n, (ll)1e6); i++) {
    if (is_pal(n, i))
      res.insert(i);
  }

  if (res.empty()) cout << "*\n";
  for (auto x : res) cout << x << ' ';
  cout << '\n';
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
