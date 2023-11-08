#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

bool has_7(int n, int base) {
  while (n) {
    auto [d, r] = div(n, base);
    if (r == 7) return true;
    n = d;
  }
  return false;
}

void solve()
{
  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += !(has_7(i, 10) or has_7(i, 8));
  }
  cout << ans << '\n';
}

int32_t main()
{
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
