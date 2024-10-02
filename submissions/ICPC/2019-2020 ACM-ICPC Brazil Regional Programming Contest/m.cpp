#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> xs(n);

  for (auto &xi : xs)
    cin >> xi;

  ll ans = 1;
  ll cur = 1;

  for (int i = 0; i + 1 < n; i++) {
    if (xs[i + 1] - xs[i] > x) {
      ans = max(ans, cur);
      cur = 1;
    } else {
      cur++;
    }
  }

  ans = max(ans, cur);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
