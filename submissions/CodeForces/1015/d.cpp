#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, k, s;
  cin >> n >> k >> s;

  if (s < k or s > (n - 1) * k) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  auto [a, b] = div(s, k);
  ll pos = 1;
  for (int i = 0; i < k; i++) {
    assert(1 <= pos and pos <= n);
    auto d = a + (b-- > 0 ? 1 : 0);
    cout << (pos += (i&1 ? -d : d)) << " \n"[i == k-1];
  }
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
