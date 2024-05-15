#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

bool is_prime(ll x)
{
  for (ll i = 2; i*i <= x; i++)
    if (x % i == 0)
      return false;
  return x > 1;
}

void solve() {
  int n;
  cin >> n;
  if (is_prime(n)) cout << "1\n";
  else if ((n&1)==0 or is_prime(n-2)) cout << "2\n";
  else cout << "3\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
